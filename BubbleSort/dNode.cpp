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
//prints
void dNode::print() {
	std::cout << this->key << " ";// << std::endl;
}