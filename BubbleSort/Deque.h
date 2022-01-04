#pragma once
#include "dNode.h"
class Deque
{
public:
	dNode* head, * tail;
	Deque(); //default constructor
	Deque(std::string filename);
	Deque(unsigned int size, int range, int start);
	~Deque(); //destructor
	void insert(int key, dNode* previous); //inserts key into previous.next
	void swap(dNode* p1, dNode* p2); //swap p1 and p2
	void swap(int p1, int p2); //uses findIndex to call swap(node, node)
	dNode* findIndex(int index);
	dNode* find(int key); //returns pointer of a given key, NULL if not found
	dNode* find_low(); //returns pointer the smallest value inside the list
	dNode* find_plow();
	void print() const; //prints head to tail
	void rprint() const; //prints tail to head
	void printTXT(std::string filename) const; //prints the list to a given file
	int sortB(bool print_iterations, bool show_counter); //bubble sort
};

