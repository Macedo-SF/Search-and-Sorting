#include "BSTree.h"

BSTree::BSTree() {
	root = NULL;
}
BSTree::BSTree(const std::string& _file) {
	std::fstream file(_file, std::ios::in);
	if (!file.is_open()) {
		std::cout << "Could not open " << _file << std::endl;
		exit(-1);
	}
	char buffer[4 + 1]; //4 chars +/0
	file.getline(buffer, 4);
	int size = std::stoi(buffer);

	for (int i = 0; i < size; i++) {
		file.getline(buffer, 4, ' ');
		int num = std::stoi(buffer);
		this->insert(num);
	}
	file.close();
}
BSTree::~BSTree() {
	this->root->destroy();
}
BSTreeNode* BSTree::insert(const int& key, BSTreeNode* current) {
	if (!current) {
		current = new BSTreeNode(key);
	}
	else if (key < current->key) {
		current->left = this->insert(key, current->left);
	}
	else {
		current->right = this->insert(key, current->right);
	}
	return current;
}

void BSTree::insert(const int& key) {
	this->root = this->insert(key, this->root);
	return;
}
void BSTree::preorder() const {
	if (this->root) {
		this->root->preorder();
	}
	std::cout << std::endl;
	return;
}
BSTreeNode* BSTree::find(const int& key, bool show_nodes) const {
	BSTreeNode* current = this->root;
	while (current) {
		if (show_nodes) {
			std::cout << current->key << std::endl;
		}
		if (current->key == key) {
			return current;
		}
		else {
			if (current->key > key) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	}
	return NULL;
}