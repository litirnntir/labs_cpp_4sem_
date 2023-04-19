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
	Node* _findMin(Node* root);
	Node* _root;
	bool _insert(Node*& root, int value);
	Node* _erase(Node* root, int key);
	Node* _contains(Node* root, int value) const;
	void _copy(const Node* obj);
	void _destructor(Node* obj);
	void _print(const Node* obj, int level = 10);
 public:
	Set();
	Set(const Set& obj);
	~Set();
	bool contains(int key) const;
	bool insert(int key);
	bool erase(int key);
	Set& operator=(const Set& obj);
	void print();
};
#endif
