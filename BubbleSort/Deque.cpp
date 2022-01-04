#include "Deque.h"
//constructor ---------------------------------------------------------------------------------------
Deque::Deque() {
	head = tail = NULL;
}
Deque::Deque(std::string filename) {
	std::fstream _file;

	_file.open(filename, std::ios::in);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-12); }

	char buffer[4 + 1]; //4 chars +/0
	_file.getline(buffer, 4);
	int size = std::stoi(buffer);
	int i = 1;
	_file.getline(buffer, 4, ' ');
	head = new dNode(std::stoi(buffer));
	dNode* current = head;

	while (i < size) {
		_file.getline(buffer, 4, ' ');
		this->insert(std::stoi(buffer), current);
		current = current->next;
		i++;
	}
	_file.close();
}
Deque::Deque(unsigned int size, int range, int start) {
	srand(time(NULL));
	head = new dNode(rand() % range + start);
	dNode* current = head;
	for (int i = 1; i < size; i++) {
		this->insert(rand() % range + start, current);
		current = current->next;
	}
}
//destructor ---------------------------------------------------------------------------------------
Deque::~Deque() {
	dNode* current = head;
	while (current != NULL) {
		current = head->next;
		delete head;
		head = current;
	}
	//head = NULL;
	tail = NULL;
}
//insert ---------------------------------------------------------------------------------------
void Deque::insert(int key, dNode* previous) {
	if (!previous) { 
		if (!head and !tail) { head = tail = new dNode(key); return; }
		if (head == tail) { 
			dNode* temp = new dNode(key);
			temp->next = head; 
			head->previous = temp;
			tail = head; 
			head = temp; 
			return; 
		}
		else { 
			dNode* temp = new dNode(key);
			temp->next = head;
			head->previous = temp;
			head = temp; 
			return;
		}
	}
	if (!previous->next) { previous->next = new dNode(key); previous->next->previous = previous; tail = previous->next; }
	else {
		dNode* temp = previous->next;
		previous->next = new dNode(key);
		previous->next->previous = previous;
		previous->next->next = temp;
		temp->previous = previous->next;
	}
}
//swap  ---------------------------------------------------------------------------------------
void Deque::swap(dNode* p1, dNode* p2) {
	if (!p1 or !p2) { return; }
	int temp = p1->key;
	p1->key = p2->key;
	p2->key = temp;
}
void Deque::swap(int p1, int p2) {
	this->swap(this->findIndex(p1), this->findIndex(p2));
}
//finds  ---------------------------------------------------------------------------------------
dNode* Deque::find(int key) {
	dNode* current = head;
	int i = 0;
	while (current) {
		i++;
		if (current->key == key) { std::cout << i << " iterations" << std::endl; return current; }
		else { current = current->next; }
	}
	std::cout << i << " iterations" << std::endl;
	return NULL;
}
dNode* Deque::find_low() {
	if (!head) { return head; } //if head is NULL, next line would break
	dNode* current = head->next;
	dNode* ret = head;
	int i = 0;
	while (current) {
		i++;
		if (current->key < ret->key) { ret = current; }
		current = current->next;
	}
	std::cout << i << " iterations" << std::endl;
	return ret;
}
dNode* Deque::find_plow() {
	if (!head) { return head; } //if head is NULL, next line would break
	dNode* current = head;
	dNode* ret = head;
	int i = 0;
	while (current->next) {
		i++;
		if (current->next->key < ret->next->key) { ret = current; }
		current = current->next;
	}
	std::cout << i << " iterations" << std::endl;
	return ret;
}
dNode* Deque::findIndex(int index) {
	dNode* current = head;
	int i = 0;
	while (i != index) {
		i++;
		current = current->next;
	}
	return current;
}
//prints ---------------------------------------------------------------------------------------
void Deque::print() const {
	dNode* current = head;
	while (current != NULL) {
		current->print();
		current = current->next;
	}
	std::cout << std::endl;
}
void Deque::rprint() const {
	dNode* current = tail;
	while (current != NULL) {
		current->print();
		current = current->previous;
	}
	std::cout << std::endl;
}
void Deque::printTXT(std::string filename) const {
	std::fstream _file;

	_file.open(filename, std::ios::out | std::ios::trunc);
	if (!_file.is_open()) { std::cout << "File could not be opened" << std::endl; exit(-11); }

	dNode* current = head;
	int i = 0;
	while (current) {
		current = current->next;
		i++;
	}

	_file << i << std::endl;
	current = head;
	while (current) {
		_file << current->key;
		current = current->next;
		if (current) { _file << ' '; }
	}

	_file.close();
}
// sorting ---------------------------------------------------------------------------------------------------
int Deque::sortB(bool print_iterations, bool show_counter) {
	int counter = 0;
	bool swapped = true;
	dNode* currentSort = NULL;
	dNode* aux = NULL;
	while (swapped) {
		swapped = false;
		dNode* current = this->head;
		while (current->next != currentSort) {
			if (current->key > current->next->key) {
				swapped = true;
				aux = current;
				this->swap(current, current->next);
				//counter += 1; //count swaps
			}
			counter += 1; //count comparisons
			current = current->next;
		}
		if(print_iterations){ this->print(); }
		if (aux) { currentSort = aux->next; } //if sorted
	}
	if (show_counter) { std::cout << counter << std::endl; }
	return counter; //simplest solution to exporting I could find
}