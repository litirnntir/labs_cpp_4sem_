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
	if (root->_left)
	{
		return _findMin(root->_left);
	}
	else
	{
		return root;
	}
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
void Set::_copy(const Node* obj)
{
	insert(obj->_data);
	if(obj->_left)
		_copy(obj->_left);
	if(obj->_right)
		_copy(obj->_right);
}
Set::Set(const Set& obj)
{
	_destructor(_root);
	_copy(obj._root);
}
Set::~Set()
{
	if (_root)
		_destructor(_root);
}
void Set::_destructor(Node* obj)
{
	if(obj->_left)
		_destructor(obj->_left);
	if(obj->_right)
		_destructor(obj->_right);
	delete obj;
}
Set::Set()
{
	_root = nullptr;
}
Set& Set::operator=(const Set& obj)
{
	_copy(obj._root);
	return (*this);
}



