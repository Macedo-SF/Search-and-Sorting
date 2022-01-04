#pragma once

#include <iostream>

class BSTreeNode
{
public:
	int key;
	BSTreeNode* left, * right;//children
	BSTreeNode();
	BSTreeNode(const int& key);
	~BSTreeNode();
	void preorder();
	void destroy();
};