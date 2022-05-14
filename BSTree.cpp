#include "BSTree.h"
#include "BSTreeException.h"

BSTree::~BSTree()
{
	if (root != nullptr)
		MakeEmpty(root);
}

bool BSTree::IsEmpty()
{
	return root == nullptr;
}

void BSTree::MakeEmpty(BSTreeNode* node)
{
	if (node == nullptr)
		return;
	MakeEmpty(node->getLeft());
	MakeEmpty(node->getRight());
	delete node;
}

Pair BSTree::Min()
{
	BSTreeNode* temp = root;
	while (temp->getLeft() != nullptr) {
		temp = temp->getLeft();
	}
	return temp->getValue();
}

Pair BSTree::MaxPair()
{
	BSTreeNode* parent = nullptr;
	BSTreeNode* temp = MaxNode(root, parent);
	return temp->getValue();
}

BSTreeNode* BSTree::MaxNode(BSTreeNode* root, BSTreeNode*& parent)
{
	BSTreeNode* temp = root;
	while (temp->getRight()) {
		parent = temp;
		temp = temp->getRight();
	}
	return temp;
}

void BSTree::PrintTree()
{
	if (root != nullptr)
		root->Inorder();
}

BSTreeNode* BSTree::Find(int key, BSTreeNode*& parent, bool& leftChild)
{
	BSTreeNode* temp = parent;
	while (temp != nullptr) {
		if (key == (temp->getValue()).getPriority())
			return temp;
		else if (key < (temp->getValue()).getPriority()) {
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
	return nullptr;
}

void BSTree::Insert(Pair item, int& NumComp)
{
	BSTreeNode* temp = root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newNode;
	bool grabege;
	if (Find(item.getPriority(), parent, grabege) != nullptr)
		throw BSTreeException("Invalid input");
	parent = nullptr;
	while (temp != nullptr) {
		NumComp++;
		parent = temp;
		if (item.getPriority() < (temp->getValue()).getPriority())
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}
	newNode = new BSTreeNode(item, nullptr, nullptr);
	NumComp = (parent == nullptr) ? NumComp : NumComp + 1;
	if (parent == nullptr)
		root = newNode;
	else if (item.getPriority() < (parent->getValue()).getPriority())
		parent->setLeft(newNode);
	else
		parent->setRight(newNode);
}

void BSTree::Delete(int key)
{
	bool leftChild = false;
	BSTreeNode* parent = root;
	BSTreeNode* temp = Find(key, parent, leftChild);
	DeleteTheNode(temp, parent, leftChild);
}

void BSTree::DeleteTheNode(BSTreeNode* toDelete, BSTreeNode* parent, bool leftChild)
{
	if (toDelete->getLeft() && toDelete->getRight())
	{
		BSTreeNode* parentMaxInTree=nullptr;
		BSTreeNode* MaxInTree = MaxNode(toDelete->getLeft(),parentMaxInTree);
		swap(MaxInTree, toDelete, false, leftChild, parentMaxInTree, parent);
		DeleteTheNode(toDelete, parentMaxInTree, false);
	}
	else if (toDelete->getLeft())
	{
		BSTreeNode* child = new BSTreeNode(toDelete->getLeft()->getValue(), toDelete->getLeft()->getLeft(), toDelete->getLeft()->getRight());
		if (leftChild)
			parent->setLeft(child);
		else
			parent->setRight(child);
		delete(toDelete);
	}
	else if (toDelete->getRight())
	{
		BSTreeNode* child = new BSTreeNode(toDelete->getRight()->getValue(), toDelete->getRight()->getLeft(), toDelete->getRight()->getRight());
		if (leftChild)
			parent->setLeft(child);
		else
			parent->setRight(child);
		delete(toDelete);
	}
	else
		return;
}
void BSTree::swap(BSTreeNode*& node, BSTreeNode*& replace, bool leftChild, bool releftChild, BSTreeNode*& pnode, BSTreeNode*& preplace)
{
	BSTreeNode* tmp= new BSTreeNode(node->getValue(), node->getLeft(), node->getRight());
	node->setLeft(replace->getLeft());
	node->setRight(replace->getRight());
	replace->setLeft(tmp->getLeft());
	replace->setRight(tmp->getRight());
	if (leftChild)
		pnode->setLeft(replace);
	else
		pnode->setRight(replace);

	if (releftChild)
		preplace->setLeft(node);
	else
		preplace->setRight(node);

}
