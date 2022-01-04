#include "dNode.h"
//constructors
dNode::dNode() {
	next = NULL;
	previous = NULL;
	key = 0;
	//default is null/empty
}
dNode::dNode(int input) {
	key = input;
	next = NULL;
	previous = NULL;
}
//destructor
dNode::~dNode() {
	//
}
//operators
void dNode::operator=(const dNode& right) {
	key = right.key;
	next = right.next;
	previous = right.previous;
}
bool operator ==(const dNode& left, const dNode& right) {
	if (left.key == right.key and left.next == right.next and left.previous == right.previous) {
		return true;
	}
	return false;
}
bool operator !=(const dNode& left, const dNode& right) {
	if (left.key == right.key and left.next == right.next and left.previous == right.previous) {
		return false;
	}
	return true;
}
//prints
void dNode::print() {
	std::cout << this->key << std::endl;
}