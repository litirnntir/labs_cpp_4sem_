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
	while (root != NULL && root->_data != value)
	{
		if (value == root->_data)
		{
			return root;
		}
		else if (value < root->_data)
		{
			root = root->_left;
		}
		else
		{
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
	if (obj->_left)
		_copy(obj->_left);
	if (obj->_right)
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
	if (obj->_left)
		_destructor(obj->_left);
	if (obj->_right)
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
void Set::_print(const Node* obj, int level)
{
	if (obj)
	{
		_print(obj->_right, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << " ";
		std::cout << obj->_data << std::endl;
		_print(obj->_left, level + 1);
	}
}

void Set::print()
{
	if (!_root) throw "It is empty";
	_print(_root);
}

unsigned char height(Node* p)
{
	if (p) return p->_height;
	else return 0;
}

void Set::_fixHeight(Node* p)
{
	unsigned char hl = height(p->_left);
	unsigned char hr = height(p->_right);
	if (hl > hr)
	{
		p->_height = hl + 1;
	}
	else
	{
		p->_height = hr + 1;
	}
}

int Set::_balanceFactor(Node* p)
{
	return height(p->_right) - height(p->_left);
}

Node* Set::_rotateRight(Node* p)
{
	Node* q = p->_left;
	p->_left = q->_right;
	q->_right = p;
	_fixHeight(p);
	_fixHeight(q);
	return q;
}

Node* Set::_rotateLeft(Node* q)
{
	Node* p = q->_right;
	q->_right = p->_left;
	p->_left = q;
	_fixHeight(q);
	_fixHeight(p);
	return p;
}

Node* Set::_balance(Node* root)
{
	_fixHeight(root);
	if (_balanceFactor(root) == -2)
	{
		if (_balanceFactor(root->_left) > 0)
			root->_left = _rotateLeft(root->_left);
		return _rotateRight(root);
	}
	if (_balanceFactor(root) == 2)
	{
		if (_balanceFactor(root->_right) < 0)
			root->_right = _rotateRight(root->_right);
		return _rotateLeft(root);
	}
	return root;
}

