#pragma once

#include <fstream>
#include <iostream>
#include <string>

class dNode
{
public:
	dNode* next, * previous; //points to nodes before and after it
	int key; //content of node
	dNode(); //default constructor
	dNode(int input); //default constructor
	~dNode(); //default destructor
	void print();
	void operator =(const dNode& right); //assignement operator ***
	friend bool operator ==(const dNode& left, const dNode& right); //bool equality operator ***
	friend bool operator !=(const dNode& left, const dNode& right); //bool equality operator ***
};

