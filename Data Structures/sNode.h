#pragma once

#include <fstream>
#include <iostream>
#include <string>

class sNode
{
public:
	sNode* next; //points to nodes before and after it
	int key; //content of node
	sNode(); //default constructor
	sNode(int input); //default constructor
	~sNode(); //default destructor
	void print();
	void rprint();
	void operator =(const sNode& right); //assignement operator ***
	friend bool operator ==(const sNode& left, const sNode& right); //bool equality operator ***
	friend bool operator !=(const sNode& left, const sNode& right); //bool equality operator ***
};