#include "PhyList.h"

void line() {
	std::cout << "------------------------------" << std::endl;
}

int main() {
	//test 1
	PhyList l1("test.txt");

	l1.print(); line();

	l1.heapSort(true, false); line();

	l1.print(); line();

	//test 2
	std::fstream myFile;
	myFile.open("heapSort.csv", std::ios::out | std::ios::trunc);
	if (!myFile.is_open()) { exit(-1); }
	myFile << "Size,Access Count" << std::endl;

	int counter = 1;
	while (counter <= 100) {
		PhyList l2(counter, 1000, 1);
		myFile << counter << ',' << l2.heapSort(false, true) << std::endl;
		counter++;
	}

	myFile.close();

	//test 3
	myFile.open("heapSort1K.csv", std::ios::out | std::ios::trunc);
	if (!myFile.is_open()) { exit(-1); }
	myFile << "Size,Access Count" << std::endl;

	counter = 1;
	while (counter <= 1000) {
		PhyList l2(counter, 10000, 1);
		myFile << counter << ',' << l2.heapSort(false, true) << std::endl;
		counter++;
	}

	myFile.close();

	return 0;
}