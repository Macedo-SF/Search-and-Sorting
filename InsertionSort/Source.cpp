#include "DynList.h"

void line() {
	std::cout << "------------------------------" << std::endl;
}

int main() {
	//test 1
	DynList l1("test.txt");

	l1.print(); line();

	l1.insertion_sort(true, false); line();

	l1.print(); line();

	//test 2
	std::fstream myFile;
	myFile.open("iSort.csv", std::ios::out | std::ios::trunc);
	if (!myFile.is_open()) { exit(-1); }
	myFile << "Size,Access Count" << std::endl;

	int counter = 1;
	while (counter <= 100) {
		DynList l2(counter, 1000, 1);
		myFile << counter << "," << l2.insertion_sort(false, true) << std::endl;
		counter++;
	}

	myFile.close();

	return 0;
}