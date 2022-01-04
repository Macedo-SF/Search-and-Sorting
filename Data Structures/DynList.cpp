#include "DynList.h"
//constructor
DynList::DynList() {
	cSize = 0;
	mSize = block;
	List = new int[mSize];
	for (int i = 0; i < mSize; i++) { List[i] = 0; }
}
DynList::DynList(std::string filename) {
	std::fstream _file;

	_file.open(filename, std::ios::in);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-12); }

	char buffer[4 + 1]; //4 chars +/0
	_file.getline(buffer, 4);
	cSize = mSize = std::stoi(buffer);
	List = new int[mSize];
	int i = 0;

	while (i<cSize) {
		_file.getline(buffer, 4,' ');
		List[i] = std::stoi(buffer);
		i++;
	}
	_file.close();
}
DynList::DynList(unsigned int size, int range, int start) {
	cSize = mSize = size;
	List = new int[mSize];
	srand(time(NULL));
	for (int i = 0; i < mSize; i++) { List[i] = rand() % range + start; }
}
//destructor
DynList::~DynList() {
	delete[]List;
	cSize = mSize = 0;
}
//insertion
void DynList::insert(int key, unsigned int pos) {
	if (cSize == mSize) {
		int* tList = new int[mSize + block];
		for (int i = 0; i < cSize; i++) { tList[i] = List[i]; }
		delete[] List;
		List = tList;
		mSize += block;
	}
	if (pos < cSize and pos>=0) {
		for (int i = cSize; i > pos; i--) { List[i] = List[i-1]; }
		cSize++;
		List[pos] = key;
	}
	else {
		List[cSize] = key;
		cSize++;
	}
}
//swap
void DynList::swap(int p1, int p2) {
	if (p1 >= 0 and p1 < cSize and p2 >= 0 and p2 < cSize) {
		int temp = List[p1];
		List[p1] = List[p2];
		List[p2] = temp;
	}
}
//finds
int DynList::find(int key) {
	int i;
	for (i = 0; i < cSize; i++) {
		if (List[i] == key) { std::cout << i+1 << " iterations" << std::endl; return i; }
	}
	std::cout << i << " iterations" << std::endl;
	return -1;
}
int DynList::find_low() {
	int ret = 0, i;
	for (i = 1; i < cSize; i++) {
		if (List[i] < List[ret]) { ret = i; }
	}
	std::cout << i-1 << " iterations" << std::endl;
	return ret;
}
//prints
void DynList::print()const {
	for (unsigned int i = 0; i < cSize; i++) { std::cout << List[i] << std::endl; }
}
void DynList::rprint()const {
	for (int i = cSize - 1; i >= 0; i--) { std::cout << List[i] << std::endl; }
}
void DynList::printTXT(std::string filename) const {
	std::fstream _file;

	_file.open(filename, std::ios::out | std::ios::trunc);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-11); }

	_file << cSize << std::endl;
	for (int i = 0; i < cSize; i++) { _file << List[i]; if (i < cSize - 1) { _file << ' '; } }
	_file.close();
}