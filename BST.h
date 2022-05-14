#pragma once

#include "Func.h"
#include "BSTree.h"
#include "Pair.h"

class BST : public Func
{
public:
	string GetName() override { return "BST: "; };
	const Person& RunFunc(Person[], int n, int k, int& NumComp) override;
	int LeftSon(BSTreeNode* root);
	int LeftSonRec(BSTreeNode* root);
	BSTreeNode* kthSmallest(BSTreeNode* root, int k, int& NumComp);
};

