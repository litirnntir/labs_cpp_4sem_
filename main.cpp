#include <iostream>
#include "Set.cpp"
#include <vector>

size_t lcg()
{
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

int check()
{
	int number;
	while (!(std::cin >> number) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Incorrect number" << std::endl;
	}
	return number;
}

int menu()
{
	std::cout << "1. Insert" << std::endl;
	std::cout << "2. Contains" << std::endl;
	std::cout << "3. Erase" << std::endl;
	std::cout << "4. Print" << std::endl;
	std::cout << "5. Exercise" << std::endl;
	std::cout << "6. Time" << std::endl;
	std::cout << "7. Exit" << std::endl;
	std::cout << "Enter number: ";
	int n = check();
	while (n > 7 || n <= 0)
	{
		std::cout << "Incorrect number" << std::endl << "Enter number: ";
		n = check();
	}
	return n;
}

std::vector<int> deleteDuplicate(std::vector<int>& data)
{
	std::vector<int> result;
	bool flag = false;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		for (auto iter = it + 1; iter != data.end(); iter++)
		{
			if (*it == *iter)
			{
				data.erase(iter--);
				flag = true;
			}
		}
		if (!flag)
		{
			result.push_back(*it);
		}
		flag = false;
	}
	return result;
}

void task()
{
	int number;
	bool flag = true;
	std::vector<int> a;
	while (flag)
	{
		std::cout << "Input number: ";
		if (!(std::cin >> number) || (std::cin.peek() != '\n'))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Incorrect number" << std::endl;
		}
		else
		{
			a.push_back(number);
		}
		std::cout << "Continue?" << std::endl;
		std::cout << "1. yes" << std::endl;
		std::cout << "2. no" << std::endl;
		std::cout << "Input number: ";
		int n = check();
		while (n > 2 || n <= 0)
		{
			std::cout << "Incorrect number" << std::endl << "Input number: ";
			n = check();
		}
		if (n == 1)
			flag = true;
		else
			flag = false;
	}
	std::vector<int> tmp;
	tmp = deleteDuplicate(a);
	for (int& it : tmp)
	{
		std::cout << it;
	}
	getchar();
}

void contains(Set& obj)
{
	std::cout << "Checking an element" << std::endl;
	std::cout << "Which element?" << std::endl;
	int node = check();
	if (obj.contains(node))
		std::cout << "The node is exist";
	else
		std::cout << "The node is not exist";
	getchar();
}

void add(Set& obj)
{
	std::cout << "Add an element" << std::endl;
	std::cout << "Which element?" << std::endl;
	int node = check();
	obj.insert(node);
}

void erase(Set& obj)
{
	std::cout << "Delete an element" << std::endl;
	std::cout << "Which element?" << std::endl;
	int node = check();
	obj.erase(node);
	getchar();
}

void print(Set& obj)
{
	obj.print();
	getchar();
}


void createVector(int size)
{
	clock_t start, end;
	double mean_time = 0;
	for (int i = 0; i < 100; i += 1)
	{
		std::vector<int> tmp;
		start = clock();
		for (int j = 0; j < size; j++)
			tmp.push_back(int(lcg()));
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 100;
	std::cout << std::endl << "Time of create vector with " << size << " elements: " << mean_time << std::endl;
	getchar();
}

void searchVector(int size)
{
	clock_t start, end;
	std::vector<int> obj;
	double mean_time = 0;

	for (int j = 0; j < size; j++)
		obj.push_back(int(lcg()));

	for (int i = 0; i < 1000; i++)
	{
		int key = int(lcg());
		while (find(obj.begin(), obj.end(), key) == obj.end())
			key = int(lcg());
		start = clock();
		find(obj.begin(), obj.end(), key);
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 1000;
	std::cout << std::endl << "Time of search element in vector with " << size << " elements: " << mean_time
			  << std::endl;
	getchar();
}

void createTime(int size)
{
	clock_t start, end;
	double mean_time = 0;
	for (int i = 0; i < 100; i += 1)
	{
		Set tmp;
		start = clock();
		for (int j = 0; j < size; j++)
			tmp.insert(int(lcg()));
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 100;
	std::cout << std::endl << "Time of create tree with " << size << " elements: " << mean_time << std::endl;
	createVector(size);
	getchar();
}

void searchTime(int size)
{
	clock_t start, end;
	Set obj;
	double mean_time = 0;

	for (int j = 0; j < size; j++)
		obj.insert(int(lcg()));

	for (int i = 0; i < 1000; i++)
	{
		int key = int(lcg());
		while (!obj.contains(key)) key = int(lcg());
		start = clock();
		obj.contains(key);
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 1000;
	std::cout << std::endl << "Time of search element in tree with " << size << " elements: " << mean_time << std::endl;
	searchVector(size);
	getchar();
}

void addEraseVector(int size)
{
	clock_t start, end;
	double mean_time = 0;

	for (int i = 0; i < 100; i++)
	{
		std::vector<int> obj;
		for (int j = 0; j < size; j++)
			obj.push_back(int(lcg()));
		int key = int(lcg());
		while (find(obj.begin(), obj.end(), key) != obj.end())
			key = int(lcg());
		start = clock();
		obj.push_back(key);
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 100;
	std::cout << std::endl << "Time of insert element in vector with " << size << " elements: " << mean_time
			  << std::endl;
	mean_time = 0;
	for (int i = 0; i < 100; i++)
	{
		std::vector<int> obj;
		for (int j = 0; j < size; j++)
			obj.push_back(int(lcg()));
		int key = int(lcg());
		while (find(obj.begin(), obj.end(), key) == obj.end())
			key = int(lcg());
		start = clock();
		obj.erase(find(obj.begin(), obj.end(), key));
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 100;
	std::cout << std::endl << "Time of erase element in vector with " << size << " elements: " << mean_time
			  << std::endl;
	getchar();
}


void addEraseVectorTime(int size)
{
	clock_t start, end;
	double mean_time = 0;

	for (int i = 0; i < 1000; i++)
	{
		Set obj;
		for (int j = 0; j < size; j++)
			obj.insert(int(lcg()));
		int key = int(lcg());
		while (obj.contains(key)) key = int(lcg());
		start = clock();
		obj.insert(key);
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 1000;
	std::cout << std::endl << "Time of insert element in tree with " << size << " elements: " << mean_time << std::endl;
	mean_time = 0;
	for (int i = 0; i < 1000; i++)
	{
		Set obj;
		for (int j = 0; j < size; j++)
			obj.insert(int(lcg()));
		int key = int(lcg());
		while (!obj.contains(key)) key = int(lcg());
		start = clock();
		obj.erase(key);
		end = clock();
		mean_time += (double(end - start)) / (double(CLOCKS_PER_SEC));
	}
	mean_time /= 1000;
	std::cout << std::endl << "Time of erase element in tree with " << size << " elements: " << mean_time << std::endl;
	addEraseVector(size);
	getchar();
}

void time()
{
	std::cout << "What time to calculate? To press.." << std::endl;
	std::cout << "1. create tree" << std::endl;
	std::cout << "2. checking an element" << std::endl;
	std::cout << "3. delete or add" << std::endl;
	std::cout << "4. go out" << std::endl;
	std::cout << "Enter number: ";
	int n = check();
	while (n > 4 || n <= 0)
	{
		std::cout << "Incorrect number" << std::endl << "Enter number: ";
		n = check();
	}

	std::cout << "What about size of tree? To press.." << std::endl;
	std::cout << "1. 1000" << std::endl;
	std::cout << "2. 10000" << std::endl;
	std::cout << "3. 100000" << std::endl;
	std::cout << "Enter number: ";
	int size = check();
	while (size > 3 || size <= 0)
	{
		std::cout << "Incorrect number" << std::endl << "Enter number: ";
		size = check();
	}
	switch (size)
	{
	case 1:
		size = 1000;
		break;
	case 2:
		size = 10000;
		break;
	case 3:
		size = 100000;
		break;
	default:
		break;
	}
	if (n == 1)
	{
		createTime(size);
	}
	if (n == 2)
	{
		searchTime(size);
	}
	if (n == 3)
	{
		addEraseVectorTime(size);
	}
}

int main()
{
	Set obj;
	int n = menu();
	getchar();
	while (n < 7)
	{
		try
		{
			if (n == 1)
			{
				add(obj);
			}
			if (n == 2)
			{
				contains(obj);
			}
			if (n == 3)
			{
				erase(obj);
			}
			if (n == 4)
			{
				print(obj);
			}
			if (n == 5)
			{
				task();
			}
			if (n == 6)
			{
				time();
			}
		}
		catch (const char* err)
		{
			std::cout << err;
			getchar();
		}
		getchar();
		std::cout << "Input number: " << std::endl;
		n = menu();
	}
}
