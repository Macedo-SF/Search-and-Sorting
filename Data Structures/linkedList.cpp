#include "linkedList.h"
linkedList::linkedList() {
	head = NULL;
}
linkedList::linkedList(std::string filename) {
	std::fstream _file;

	_file.open(filename, std::ios::in);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-12); }

	char buffer[4 + 1]; //4 chars +/0
	_file.getline(buffer, 4);
	int size = std::stoi(buffer);
	int i = 1;
	_file.getline(buffer, 4, ' ');
	head = new sNode(std::stoi(buffer));
	sNode* current = head;

	while (i < size) {
		_file.getline(buffer, 4, ' ');
		this->insert(std::stoi(buffer), current);
		current = current->next;
		i++;
	}
	_file.close();
}
linkedList::linkedList(unsigned int size, int range, int start) {
	srand(time(NULL));
	head = new sNode(rand() % range + start);
	sNode* current = head;
	for (int i = 1; i < size; i++) { 
		this->insert(rand() % 1000 + 1, current);
		current = current->next;
	}
}
linkedList::~linkedList() {
	sNode* current = head;
	while (current) {
		head = current->next;
		delete current;
		current = head;
	}
	delete head;
}
void linkedList::insert(int key, sNode* previous) {
	if (!previous) { sNode* temp = new sNode(key); temp->next = head; head = temp; return; } //test
	if (!previous->next) { previous->next = new sNode(key); return; }
	else {
		sNode* temp = previous->next;
		previous->next = new sNode(key);
		previous->next->next = temp;
	}
}
void linkedList::swap(sNode* p1, sNode* p2) {
	if (!p1 or !p2) { return; }
	int temp = p1->key;
	p1->key = p2->key;
	p2->key = temp;
}
void linkedList::swap(int p1, int p2) {
	this->swap(this->findIndex(p1), this->findIndex(p2));
}
sNode* linkedList::find(int key) {
	sNode* current = head;
	int i = 0;
	while (current) {
		i++;
		if (current->key == key) { std::cout << i << " iterations" << std::endl; return current; }
		else { current = current->next; }
	}
	std::cout << i << " iterations" << std::endl;
	return NULL;
}
sNode* linkedList::find_low() {
	if (!head) { return head; } //if head is NULL, next line would break
	sNode* current = head->next;
	sNode* ret = head;
	int i = 0;
	while (current) {
		i++;
		if (current->key < ret->key) { ret = current; }
		current = current->next;
	}
	std::cout << i << " iterations" << std::endl;
	return ret;
}
sNode* linkedList::find_plow() {
	if (!head) { return head; } //if head is NULL, next line would break
	sNode* current = head;
	sNode* ret = head;
	int i = 0;
	while (current->next) {
		i++;
		if (current->next->key < ret->next->key) { ret = current; }
		current = current->next;
	}
	std::cout << i << " iterations" << std::endl;
	return ret;
}
sNode* linkedList::findIndex(int index) {
	sNode* current = head;
	int i = 0;
	while (i != index) {
		i++;
		current = current->next;
	}
	return current;
}
void linkedList::print() const {
	sNode* current = head;
	while (current) {
		current->print();
		current = current->next;
	}
}
void linkedList::rprint() const {
	this->head->rprint();
}
void linkedList::printTXT(std::string filename) const {
	std::fstream _file;

	_file.open(filename, std::ios::out | std::ios::trunc);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-11); }

	sNode* current = head;
	int i = 0;
	while (current) {
		current = current->next;
		i++;
	}

	_file << i << std::endl;
	current = head;
	while (current) {
		_file << current->key;
		current = current->next;
		if (current) { _file << ' '; }
	}

	_file.close();
}