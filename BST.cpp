#include "BST.h"

const Person& BST::RunFunc(Person personArr[], int n, int k, int& NumComp)
{
	Person* result = nullptr;
	BSTree* tree;
	for (int i = 0; i < n; i++)
	{
		tree->Insert(Pair(personArr[i].getName(), personArr[i].getId()), NumComp);
	}
	if (k == 1)
		result = new Person((tree->Min()).getPriority(), (tree->Min()).getData());
	else if(k==n)
		result = new Person((tree->MaxPair()).getPriority(), (tree->MaxPair()).getData());
	else
	{
		int lcount = LeftSon(tree);
		BSTreeNode* kthNode = kthSmallest(tree->getRoot(), k, lcount);
		result= new Person((kthNode->getValue()).getPriority(), (kthNode->getValue()).getData());
	}
	return *result;
}

BSTreeNode* BST::kthSmallest(BSTreeNode* root, int k, int lCount)
{
	// base case
	//if (root == nullptr) 
		//return nullptr;
	int count = lCount + 1;
	if (count == k)
		return root;
	if (count > k)
		return kthSmallest(root->getLeft(), k, lCount-1);
	// else search in right subtree
	return kthSmallest(root->getRight(), k - count, lCount);
}

int BST::LeftSon(BSTree* tree)
{
	int count = 0;
	LeftSonRec(tree->getRoot()->getLeft(), count);
	return count;
}

void BST::LeftSonRec(BSTreeNode* root, int& count)
{
	if (root == nullptr)
		return;
	count++;
	LeftSonRec(root->getLeft(), count);
	LeftSonRec(root->getRight(), count);
}