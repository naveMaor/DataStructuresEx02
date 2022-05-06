#include "BSTree.h"

BSTree::~BSTree()
{
	delete root;
	root = nullptr;
}

Pair BSTree::Min()
{
	BSTreeNode* temp = root;
	while (temp->getLeft() != nullptr) {
		temp = temp->getLeft();
	}
	return temp->getValue();
}

Pair BSTree::Max()
{
	BSTreeNode* temp = root;
	while (temp->getRight() != nullptr) {
		temp = temp->getRight();
	}
	return temp->getValue();
}

void BSTree::PrintTree()
{
	if (root != nullptr)
		root->Inorder();
}

BSTreeNode* BSTree::Find(int key)
{
	BSTreeNode* temp = root;
	while (temp != nullptr) {
		if (key == (temp->getValue()).getPriority())
			return temp;
		else if (key < (temp->getValue()).getPriority())
			temp = temp->getLeft();
		else
			temp = temp->getRight();

	}
	return nullptr;
}

void BSTree::Insert(Pair item)
{
	//if (Find(item.getPriority()) != nullptr)
		//Handle error
	BSTreeNode* temp = root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newNode;

	while (temp != nullptr) {
		parent = temp;
		if (item.getPriority() < (temp->getValue()).getPriority())
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}
	newNode = new BSTreeNode(item, nullptr, nullptr);
	if (parent == nullptr)
		root = newNode;
	else if (item.getPriority() < (parent->getValue()).getPriority())
		parent->setLeft(newNode);
	else
		parent->setRight(newNode);
}

void BSTree::Delete(int key)
{
	BSTreeNode* temp = root;
	BSTreeNode* parent = temp;
	bool found = false;
	bool leftChild = false;
	while (temp != nullptr && !found) {
		if (key == (temp->getValue()).getPriority())
			found = true;
		else if (key < (temp->getValue()).getPriority())
		{
			parent = temp;
			leftChild = true;
			temp = temp->getLeft();
		}
		else
		{
			parent = temp;
			leftChild = false;
			temp = temp->getRight();
		}
	}
	if (temp->getLeft() != nullptr && temp->getRight() != nullptr) {
		BSTreeNode* maxTemp = temp->getLeft();
		BSTreeNode* tempParent = temp;
		while (maxTemp->getRight() != nullptr)
		{
			tempParent = maxTemp;
			maxTemp = maxTemp->getRight();
		}
		BSTreeNode* tmp = temp;
		temp = maxTemp;
		maxTemp = tmp;
		parent = tempParent;
	}
	if (temp->getLeft() != nullptr)
	{
		if (leftChild)
			parent->setLeft(temp->getLeft());
		else
			parent->setRight(temp->getLeft());
	}
	if (temp->getRight() != nullptr)
	{
		if (leftChild)
			parent->setLeft(temp->getRight());
		else
			parent->setRight(temp->getRight());
	}

}