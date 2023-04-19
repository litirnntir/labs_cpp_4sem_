#include <iostream>
#include "Set.cpp"

int main()
{
	Set a = Set();
	a.insert(5);
	a.insert(2);
	a.insert(3);
	a.insert(1);
	a.insert(5);
	a.erase(5);
	std::cout << a.contains(1);
	a.print();
}
