#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#define block 100

class DynList
{
private:
	int *List; //considered using vector<int>
	unsigned int cSize, mSize;
public:
	DynList(); //default constructor
	DynList(std::string filename); //read from file
	DynList(unsigned int size, int range, int start); //generate random list
	~DynList(); //default destructor
	void insert(int key, unsigned int pos); //inserts key into pos
	void swap(int p1, int p2); //swap p1 and p2
	int find(int key); //returns the position of a given key, -1 if not found
	int find_low(); //returns the smallest value inside the list
	void print() const; //prints whole list
	void rprint() const; //prints whole list from end
	void printTXT(std::string filename) const; //prints the list to a given file
};

