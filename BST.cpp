#include "BST.h"
#include "BSTreeException.h"

const Person& BST::RunFunc(Person personArr[], int n, int k, int& NumComp)
{
	Person* result = nullptr;
	BSTree* tree=new BSTree;
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
		BSTreeNode* kthNode = kthSmallest(tree->getRoot(), k, NumComp);
		result= new Person((kthNode->getValue()).getPriority(), (kthNode->getValue()).getData());
	}
	return *result;
}

BSTreeNode* BST::kthSmallest(BSTreeNode* root, int k, int& NumComp)
{
	// base case
	if (root == nullptr) 
		return nullptr;
	NumComp++;
	int count = LeftSon(root) + 1;
	if (count == k)
		return root;	
	if (count > k)
		return kthSmallest(root->getLeft(), k, NumComp);
	// else search in right subtree
	return kthSmallest(root->getRight(), k - count, NumComp);
}

int BST::LeftSon(BSTreeNode* root)
{
	return LeftSonRec(root->getLeft());
}

int BST::LeftSonRec(BSTreeNode* root)
{
	if (root == nullptr)
		return 0;
	else if (root->getLeft() == nullptr && root->getRight() == nullptr)
		return 1;
	else if (root->getLeft() == nullptr)
		return LeftSonRec(root->getRight()) + 1;
	else if (root->getRight() == nullptr)
		return LeftSonRec(root->getLeft()) + 1;
	else
		return LeftSonRec(root->getLeft()) + LeftSonRec(root->getRight()) + 1;
}
