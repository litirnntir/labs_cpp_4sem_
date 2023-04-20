#include <iostream>
#include "Set.cpp"
#include <vector>

int check()
{
	int number;
	while (!(std::cin >> number) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Incorrect value" << std::endl;
	}
	return number;
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
		std::cout << "Input number = ";
		if (!(std::cin >> number) || (std::cin.peek() != '\n'))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Incorrect value" << std::endl;
		}
		else
		{
			a.push_back(number);
		}
		std::cout << "Continue?" << std::endl;
		std::cout << "1. yes" << std::endl;
		std::cout << "2. no" << std::endl;
		std::cout << "Input choose:";
		int n = check();
		while (n > 2 || n <= 0)
		{
			std::cout << "Incorrect value" << std::endl << "Input choose:";
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

int menu()
{
	std::cout << "1. Add an element" << std::endl;
	std::cout << "2. Checking an element" << std::endl;
	std::cout << "3. Delete an element" << std::endl;
	std::cout << "4. Print" << std::endl;
	std::cout << "5. Exercise" << std::endl;
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

int main()
{
	menu();
}
