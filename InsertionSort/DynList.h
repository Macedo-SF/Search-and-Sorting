#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class DynList
{
private:
	std::vector<int> List;
public:
	DynList(); //default constructor
	DynList(const std::string &filename); //read from file
	DynList(const unsigned int &size, const int &range, const int &start); //generate random list
	~DynList(); //default destructor
	void insert(const int &key, const unsigned int &pos); //inserts key into pos
	void swap(const int &p1, const int &p2); //swap p1 and p2
	int find(const int &key) const; //returns the position of a given key, -1 if not found
	int find_low() const; //returns the smallest value inside the list
	void print() const; //prints whole list
	void rprint() const; //prints whole list from end
	void printTXT(const std::string &filename) const; //prints the list to a given file
	int insertion_sort(const bool &print_iterations, const bool &show_counter);//insertion sorting
};