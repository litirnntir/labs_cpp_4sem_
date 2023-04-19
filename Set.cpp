#include "Set.h"

bool Set::_insert(Node*& root, int value)
{
	if (!root)
	{
		root = new Node(value);
		return true;
	}
	if (root->_data == value)
	{
		return false;
	}
	if (root->_data > value)
	{
		return _insert(root->_left, value);
	}
	else
	{
		return _insert(root->_right, value);
	}
}
bool Set::insert(int key)
{
	return _insert(_root, key);
}
