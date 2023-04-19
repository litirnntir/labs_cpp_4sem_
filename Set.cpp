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

Node* Set::_findMin(Node* root)
{
	return root->_left ? _findMin(root->_left) : root;
}

Node* Set::_erase(Node* root, int key)
{
	if (root == NULL) return root;
	else if (key < root->_data) root->_left = _erase(root->_left, key);
	else if (key > root->_data) root->_right = _erase(root->_right, key);
	else
	{
		// Case 1:  No child
		if (root->_left == NULL && root->_right == NULL)
		{
			delete root;
			root = NULL;
		}
			//Case 2: One child
		else if (root->_left == NULL)
		{
			struct Node* temp = root;
			root = root->_right;
			delete temp;
		}
		else if (root->_right == NULL)
		{
			struct Node* temp = root;
			root = root->_left;
			delete temp;
		}
			// case 3: 2 children
		else
		{
			struct Node* temp = _findMin(root->_right);
			root->_data = temp->_data;
			root->_right = _erase(root->_right, temp->_data);
		}
	}
	return root;
}
bool Set::erase(int key)
{
	if (!_contains(_root, key))
	{
		return false;
	}
	_root = _erase(_root, key);
	return true;
}
Node* Set::_contains(Node* root, int value) const
{
	while (root != NULL && root->_data != value) {
		if (value == root->_data) {
			return root;
		}
		else if (value < root->_data) {
			root = root->_left;
		}
		else {
			root = root->_right;
		}
	}
	return root;
}
bool Set::contains(int key) const
{
	if (_contains(_root, key))
	{
		return true;
	}
	else
	{
		return false;
	}
}
