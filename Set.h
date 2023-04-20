#ifndef LABS_CPP_4SEM___SET_H_
#define LABS_CPP_4SEM___SET_H_

#include <iostream>

struct Node
{
	int _data;
	Node* _left;
	Node* _right;
	unsigned char _height;
	Node(int value = 0)
	{
		_data = value;
		_left = _right = NULL;
		_height = 1;
	}
};

class Set
{
 private:
	Node* _root;
	void _print(const Node* obj, int level = 10);
	Node* _contains(Node* root, int value) const;
	Node* _insert(Node* root, int data);
	Node* _erase(Node* root, int key);
	void _copy(const Node* obj);
	void _destructor(Node* obj);
	Node* _findMin(Node* root);
	void _fixHeight(Node* p);
	Node* _balance(Node* root);
	int _balanceFactor(Node* p);
	Node* _rotateRight(Node* p);
	Node* _rotateLeft(Node* q);
	Node* _balanced(Node* root);
 public:
	Set& operator=(const Set& obj);
	bool contains(int key) const;
	bool insert(int key);
	bool erase(int key);
	Set(const Set& obj);
	void print();
	~Set();
	Set();
};
#endif
