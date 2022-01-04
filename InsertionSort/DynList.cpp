#include "DynList.h"

//constructor
DynList::DynList() {
	//std
}
DynList::DynList(const std::string &filename) {
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
DynList::DynList(const unsigned int &size, const int &range, const int &start) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		List.push_back(rand() % range + start);
	}
}
//destructor
DynList::~DynList() {
	List.clear(); //not really needed
}
//insertion
void DynList::insert(const int &key, const unsigned int &pos) {
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
void DynList::swap(const int &p1, const int &p2) {
	if (p1 >= 0 and p1 < (List.size() - 1) and p2 >= 0 and p2 < (List.size() - 1)) {
		int temp = List[p1];
		List[p1] = List[p2];
		List[p2] = temp;
	}
}
//find
int DynList::find(const int &key) const {
	int i;
	for (i = 0; i < List.size(); i++) {
		if (List[i] == key) { std::cout << i + 1 << " iterations" << std::endl; return i; }
	}
	std::cout << i << " iterations" << std::endl;
	return -1;
}
int DynList::find_low() const {
	int ret = 0, i;
	for (i = 1; i < List.size(); i++) {
		if (List[i] < List[ret]) { ret = i; }
	}
	std::cout << i - 1 << " iterations" << std::endl;
	return ret;
}
//print
void DynList::print()const {
	for (unsigned int i = 0; i < List.size(); i++) {
		std::cout << List[i] << " "; 
	}
	std::cout << std::endl;
}
void DynList::rprint()const {
	for (int i = List.size() - 1; i >= 0; i--) { 
		std::cout << List[i] << " ";
	}
	std::cout << std::endl;
}
void DynList::printTXT(const std::string &filename) const {
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
int DynList::insertion_sort(const bool& print_iterations, const bool& show_counter) {
	int counter = 0;
	if (!List.empty()) { //if empty, it'd break when trying to access
		for (int i = 1; i < List.size(); i++) { //pseudocode says to n-1
			int j = i - 1;
			int current_value = List[i];
			counter++;
			while (j >= 0 and current_value < List[j]) {
				List[j + 1] = List[j];
				j--;
				counter+=3;
			}
			List[j + 1] = current_value;
			counter++;
			if (print_iterations) {
				this->print();
			}
		}
	}
	if (show_counter) {
		std::cout << counter << " memory accesses" << std::endl;
	}
	return counter;
}