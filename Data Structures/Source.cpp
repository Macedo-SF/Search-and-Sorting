#include "PhyList.h"
#include "linkedList.h"
#include "Deque.h"

using namespace std;

void line() {
	cout << "-----" << endl;
}

int main() {

	PhyList l1("test.txt");
	linkedList l2("test.txt");
	Deque l3("test.txt");

	l1.print(); line();
	l2.print(); line();
	l3.print(); line();

	l1.insert(11, 10);
	l1.insert(2, 4);
	l1.insert(7, 0);

	l2.insert(11, l2.findIndex(9)); //aponto para a p9 para inserir na p10
	l2.insert(2, l2.findIndex(3)); //aponto para p3 para inserir na p4
	l2.insert(7, NULL); //aponto para NULL para inserir na p0(head)

	l3.insert(11, l3.findIndex(9));
	l3.insert(2, l3.findIndex(3));
	l3.insert(7, NULL);

	l1.print(); line();
	l2.print(); line();
	l3.print(); line();

	l1.find(10);
	l1.find(8);
	l1.find(12); line();

	l2.find(10);
	l2.find(8);
	l2.find(12); line();

	l3.find(10);
	l3.find(8);
	l3.find(12); line();

	l1.swap(3, 4);
	l1.swap(0, 6);
	l1.swap(6, 12);

	l2.swap(3, 4);
	l2.swap(0, 6);
	l2.swap(6, 12);

	l3.swap(3, 4);
	l3.swap(0, 6);
	l3.swap(6, 12);

	l1.print(); line();
	l2.print(); line();
	l3.print(); line();

	cout << l1.find_low() << endl;
	cout << l2.find_plow()->key << endl;
	cout << l3.find_plow()->key << endl; line();

	l1.rprint(); line();
	l2.rprint(); line();
	l3.rprint(); line();

	DynList r1(100, 1000, 1);
	linkedList r2(100, 1000, 1);
	Deque r3(100, 1000, 1);

	r1.print(); line();
	r2.print(); line();
	r3.print(); line();

	cout << r1.find_low() << endl;
	cout << r2.find_plow()->key << endl;
	cout << r3.find_plow()->key << endl; line();

	r1.rprint(); line();
	r2.rprint(); line();
	r3.rprint(); line();

	l1.printTXT("l1.txt");
	l2.printTXT("l2.txt");
	l3.printTXT("l3.txt");

	return 0;
}
//find_low <---
//os testes pedem o ponteiro anterior, porem a impletação já estava feita, 
//julgo que a alteração venha a ser necessária para usar com a insert
