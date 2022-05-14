#pragma once

#include "BSTreeNode.h"

class BSTree {
private:
	BSTreeNode *root= nullptr;
public:
	BSTree():root(nullptr){}
	BSTree(BSTreeNode* _root) :root(_root) {}
	~BSTree();
	BSTreeNode* getRoot() { return root; }
	void setRoot(BSTreeNode* newRoot) { root = newRoot; }
	BSTreeNode* Find(int key, BSTreeNode*& parent, bool& leftChild);
	void Insert(Pair item, int& NumComp);
	void Delete(int key);
	void DeleteTheNode(BSTreeNode* toDelete, BSTreeNode* parent, bool leftChild);
	Pair Min();
	Pair MaxPair();
	BSTreeNode* MaxNode(BSTreeNode* root, BSTreeNode*& parent);
	void PrintTree();
	bool IsEmpty();
	void MakeEmpty(BSTreeNode* node);
	void swap(BSTreeNode*& node, BSTreeNode*& replace, bool leftChild, bool releftChild, BSTreeNode*& pnode, BSTreeNode*& preplace);
};

