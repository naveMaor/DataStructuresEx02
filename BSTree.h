#pragma once

#include "BSTreeNode.h"

class BSTree {
private:
	BSTreeNode *root;
public:
	BSTree():root(nullptr){}
	~BSTree();
	BSTreeNode* Find(int key);
	void Insert(Pair item);
	void Delete(int key);
	Pair Min();
	Pair Max();
	void PrintTree();
};

