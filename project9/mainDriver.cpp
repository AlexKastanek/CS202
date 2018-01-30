#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

int main() {

	Queue list, list2;
	int value = 1;
	int dequeued;

	for (int i = 0; i < 10; i++) {
		list.enqueue(value);
		value++;
		cout << list << endl;
	}

	for (int i = 0; i < 5; i++) {
		list.dequeue(dequeued);
		cout << list << endl;
	}

	for (int i = 0; i < 10; i++) {
		list.enqueue(value);
		value++;
		cout << list << endl;
	}

	for (int i = 0; i < 7; i++) {
		list.dequeue(dequeued);
		cout << list << endl;
	}

	list2 = list;

	cout << list2 << endl;

	return 0;
}

