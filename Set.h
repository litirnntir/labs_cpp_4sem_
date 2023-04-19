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
	bool _insert(Node*& root, int value);
 public:
	bool insert(int key);
};
#endif
