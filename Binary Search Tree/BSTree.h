#pragma once

#include "BSTreeNode.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

class BSTree
{
	BSTreeNode* root;
	BSTreeNode* insert(const int& key, BSTreeNode* current);//hide from std access
public:
	BSTree();
	BSTree(const std::string& _file);
	~BSTree();
	void insert(const int& key);//looks better, useless
	void preorder() const;
	BSTreeNode* find(const int& key,bool show_nodes=true) const;
};