#include "sNode.h"

//constructors
sNode::sNode() {
	next = NULL;
	key = 0;
}
sNode::sNode(int input) {
	next = NULL;
	key = input;
}
//destructor
sNode::~sNode() {
	//
}
//prints
void sNode::print() {
	std::cout << this->key << std::endl;
}
void sNode::rprint() {
	if (this->next) {
		this->next->rprint();
	}
	std::cout << this->key << std::endl;
}
//operators
void sNode::operator=(const sNode& right) {
	key = right.key;
	next = right.next;
}
bool operator ==(const sNode& left, const sNode& right) {
	if (left.key == right.key and left.next == right.next) {
		return true;
	}
	return false;
}
bool operator !=(const sNode& left, const sNode& right) {
	if (left.key == right.key and left.next == right.next) {
		return false;
	}
	return true;
}