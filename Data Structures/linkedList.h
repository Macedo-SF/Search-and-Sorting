#pragma once
#include "sNode.h"
class linkedList
{
public:
	//attributes
	sNode* head;
	//methods
	linkedList();
	linkedList(std::string filename);
	linkedList(unsigned int size, int range, int start);
	~linkedList();
	void insert(int key, sNode* previous); //inserts key into previous.next
	void swap(sNode* p1, sNode* p2); //swap p1 and p2
	void swap(int p1, int p2); //uses findIndex to call swap(node, node)
	sNode* findIndex(int index);
	sNode* find(int key); //returns pointer of a given key, NULL if not found
	sNode* find_low(); //returns pointer the smallest value inside the list
	sNode* find_plow();
	void print() const; //prints whole list
	void rprint() const; //prints whole list from end
	void printTXT(std::string filename) const; //prints the list to a given file
};

