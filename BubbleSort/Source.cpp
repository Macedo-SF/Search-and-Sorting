#include "Deque.h"
#include <fstream>

using namespace std;

void line() {
	cout << "-----" << endl;
}

int main() {

	Deque l1("test.txt");
	l1.sortB(true, true);
	
	fstream myFile;
	myFile.open("export.csv",ios::out|ios::trunc);
	if (!myFile.is_open()) { exit(-1); }
	myFile << "Size,Iterations" << endl;

	int counter = 1;
	while (counter <= 100) {
		Deque l2(counter, 1000, 1);
		myFile << counter << "," << l2.sortB(false, true) << endl;
		counter++;
	}

	myFile.close();

	return 0;
}