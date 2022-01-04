#include "PhyList.h"

//constructor
PhyList::PhyList() {
	//std
}
PhyList::PhyList(const std::string& filename) {
	std::fstream _file;

	_file.open(filename, std::ios::in);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-12); }

	char buffer[4 + 1]; //4 chars +/0
	_file.getline(buffer, 4);
	int size = std::stoi(buffer);

	for (int i = 0; i < size; i++) {
		_file.getline(buffer, 4, ' ');
		int num = std::stoi(buffer);
		List.push_back(num);
	}
	_file.close();
}
PhyList::PhyList(const unsigned int& size, const int& range, const int& start) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		List.push_back(rand() % range + start);
	}
}
//destructor
PhyList::~PhyList() {
	List.clear(); //not really needed
}
//insertion
void PhyList::insert(const int& key, const unsigned int& pos) {
	if (List.max_size() == List.size()) {
		std::cout << "Max size reached" << std::endl;
		exit(-13);
	}
	List.push_back(key); //default insertion is at the back
	if (pos >= 0 and pos < (List.size() - 1)) {
		this->swap(pos, (List.size() - 1));
	}
}
//swap
void PhyList::swap(const int& p1, const int& p2) {
	if (p1 >= 0 and p1 <= (List.size() - 1) and p2 >= 0 and p2 <= (List.size() - 1)) {
		int temp = List[p1];
		List[p1] = List[p2];
		List[p2] = temp;
	}
}
//find
int PhyList::find(const int& key) const {
	int i;
	for (i = 0; i < List.size(); i++) {
		if (List[i] == key) { std::cout << i + 1 << " iterations" << std::endl; return i; }
	}
	std::cout << i << " iterations" << std::endl;
	return -1;
}
int PhyList::find_low() const {
	int ret = 0, i;
	for (i = 1; i < List.size(); i++) {
		if (List[i] < List[ret]) { ret = i; }
	}
	std::cout << i - 1 << " iterations" << std::endl;
	return ret;
}
//print
void PhyList::print()const {
	for (unsigned int i = 0; i < List.size(); i++) {
		std::cout << List[i] << " ";
	}
	std::cout << std::endl;
}
void PhyList::rprint()const {
	for (int i = List.size() - 1; i >= 0; i--) {
		std::cout << List[i] << " ";
	}
	std::cout << std::endl;
}
void PhyList::printTXT(const std::string& filename) const {
	std::fstream _file;

	_file.open(filename, std::ios::out | std::ios::trunc);
	if (!_file.is_open()) {
		std::cout << "File could not be opened" << std::endl; exit(-11);
	}

	_file << List.size() << std::endl;
	for (int i = 0; i < List.size(); i++) {
		_file << List[i];
		if (i < List.size() - 1) {
			_file << ' ';
		}
	}
	_file.close();
}
//sorting
int PhyList::quickSort(bool show_iterations, bool count_access) {
	int counter = 1;
	quickSort(0, this->List.size() - 1, show_iterations, counter);
	if (count_access) {
		std::cout << counter << " memory accesses" << std::endl;
	}
	return counter;
}
void PhyList::quickSort(const int& floor, const int& ceiling, bool show_iterations, int&counter) {
	if (show_iterations) {
		this->print();
		std::cout << floor << "<->" << ceiling << std::endl; //easier to see
	}
	if (floor < ceiling) {
		int pi = partition(floor, ceiling,counter);
		quickSort(floor, pi - 1, show_iterations, counter);
		quickSort(pi + 1, ceiling, show_iterations, counter);
	}
}
int PhyList::partition(const int& floor, const int& ceiling, int& counter) {
	int pivot = this->List[ceiling];
	int c = floor;
	counter++;
	for (int i = floor; i < ceiling; i++) {
		if (this->List[i] < pivot) {
			this->swap(c, i);
			counter += 2;
			c++;
		}
		counter++;
	}
	this->swap(c, ceiling);
	counter += 2;
	return c;
}