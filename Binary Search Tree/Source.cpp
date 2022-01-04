#include "BSTree.h"

void line() {
	std::cout << "----------" << std::endl;
}

int main() {
	//test 1
	BSTree test1;

	test1.preorder(); line();
	test1.insert(3);
	test1.preorder(); line();
	test1.insert(2);
	test1.preorder(); line();
	test1.insert(1);
	test1.preorder(); line();

	//test 2
	BSTree test2("test.txt");

	test2.preorder(); line();
	test2.find(31, true); line();
	test2.find(58, true); line();
	test2.find(14, true); line();
	test2.find(18, true); line();

	return 0;
}