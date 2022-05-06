#pragma once

#include "Pair.h"
#include <iostream>

using namespace std;

class BSTreeNode {
private:
	Pair value;
	BSTreeNode* left, * right;
public:
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right):value(item), left(left), right(right){}
	BSTreeNode(BSTreeNode& node);
	~BSTreeNode();
	Pair getValue() { return value; }
	void setValue(Pair newValue) { value= newValue; }
	BSTreeNode* getLeft() { return left; }
	void setLeft(BSTreeNode* newLeft) { left = newLeft; }
	BSTreeNode* getRight() { return right; }
	void setRight(BSTreeNode* newRight) { right = newRight; }
	void Inorder();
	void Preorder();
	void Postorder();

};