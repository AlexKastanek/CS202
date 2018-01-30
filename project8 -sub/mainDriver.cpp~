#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

int main() {

	Stack list, list2;
	char letter = 'a';
	char popped;

	for (int i = 0; i < 10; i++) {
		list.push(letter);
		letter++;
		cout << list << endl;
	}

	for (int i = 0; i < 5; i++) {
		list.pop(popped);
		cout << list << endl;
	}

	for (int i = 0; i < 10; i++) {
		list.push(letter);
		letter++;
		cout << list << endl;
	}

	for (int i = 0; i < 10; i++) {
		list.pop(popped);
		cout << list << endl;
	}

	list2 = list;

	cout << list2 << endl;

	return 0;
}

