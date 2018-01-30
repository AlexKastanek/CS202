#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

Stack::Stack(int a) { //default constructor with value of max set to 10 if no parameters are given

	max = a;
	top = -1;
	data = new char[max];

}

Stack::Stack(const Stack& source) { //copy constructor

	max = source.max;
	top = source.top;
	data = new char[max];
	for (int i = 0; i < max; i++) {
		data[i] = source.data[i];
	}

}

Stack::~Stack() { //destructor

	top = -1;
	delete[] data;
	data = NULL;

}

Stack& Stack::operator=(const Stack& source) { //assignment operator function assigns each value in the calling class to the source

	clear();
	delete[] data;
	data = NULL;

	max = source.max;
	
	if (source.empty()) {
		top = -1;
	} else top = 0;

	data = new char[source.max];

	for (int i = 0; i < top; i++) {
		data[i] = source.data[i];
	}

	return *this;

}

bool Stack::push(char item) { //function that pushes a specified element onto the stack

	if (full()) { //if stack is full returns false
		return false;
	}

	top++; //increments top

	data[top] = item; //places new item on top

	return true;

}

bool Stack::pop(char& item) { //function that pushes the top element off of the stack

	if (empty()) { //if stack is empty returns false
		return false;
	}

	item = data[top]; //stores top in item

	data[top] = '\0'; //sets top to null character

	top--; //decrements top

	return true;

}

bool Stack::empty() const { //checks if stack is empty

	if (top == -1) { //returns true if top is -1
		return true;
	} else return false;

}

bool Stack::full() const { //checks if stack is full

	if (top == max - 1) { //returns true if top is equal to the max number of items - 1
		return true;
	} else return false;

}

bool Stack::clear() { //clears the stack

	if (empty()) { //if the stack is empty returns false
		return false;
	}

	for (int i = 0; i < max; i++) { //loop that sets each item in the stack to null
		data[i] = '\0';
	}

	top = -1; //sets top back to its default value

	return true;

}

bool Stack::operator==(const Stack& source) const { //checks to see if two stacks are equal

	if (max != source.max) { //checks each individual value in each stack and returns false if they differ
		return false;
	}

	if (top != source.top) {
		return false;
	}

	for (int i = 0; i < top; i++) {
		if (data[i] != source.data[i]) {
			return false;
		}
	}

	return true;

}

ostream& operator<<(ostream& os, const Stack& list) { //outputs the data within the stack

	for (int i = list.top; i >= 0; i--) {
		os << list.data[i];
	}

	return os;

}




