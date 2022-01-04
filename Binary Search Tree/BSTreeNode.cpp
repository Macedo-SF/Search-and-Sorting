#include "BSTreeNode.h"

BSTreeNode::BSTreeNode() {
	this->key = NULL;//must assure every node created is used
	this->left = this->right = NULL;
}
BSTreeNode::BSTreeNode(const int& key) {
	this->key = key;
	this->left = this->right = NULL;
}
BSTreeNode::~BSTreeNode() {
	//unused
}
void BSTreeNode::preorder() {
	std::cout << this->key << " ";
	if (this->left) {
		this->left->preorder();
	}
	if (this->right) {
		this->right->preorder();
	}
}
void BSTreeNode::destroy() {
	if (this->left) {
		this->left->destroy();
	}
	if (this->right) {
		this->right->destroy();
	}
	delete this;
}