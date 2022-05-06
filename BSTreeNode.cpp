#include "BSTreeNode.h"

BSTreeNode::BSTreeNode()
{
	left = right = nullptr;
}

BSTreeNode::BSTreeNode(BSTreeNode& node)
{
	setValue(node.getValue());
	setRight(node.getRight());
	setLeft(node.getLeft());
}

BSTreeNode::~BSTreeNode()
{
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
}


void BSTreeNode::Inorder()
{
	if (left != nullptr) left->Inorder();
	std::cout << value.getData();
	if (right != nullptr) right->Inorder();
}
