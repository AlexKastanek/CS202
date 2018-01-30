#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

Stack::Stack(int a) { //default constructor with value of max set to 10 if no parameters are given

	max = a;
	top = -1;
	actual = 0;
	data = new char[max];

}

Stack::Stack(const Stack& source) { //copy constructor

	max = source.max;
	top = source.top;
	actual = source.actual;
	data = new char[max];
	for (int i = 0; i < max; i++) {
		data[i] = source.data[i];
	}

}

Stack::~Stack() { //destructor

	top = -1;
	actual = 0;
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

	actual = source.actual;

	data = new char[source.max];

	for (int i = 0; i < actual; i++) {
		data[i] = source.data[i];
	}

	return *this;

}

bool Stack::push(char item) { //function that pushes a specified element onto the stack

	top = 0; //sets top to 0

	if (empty()) { //if the stack is empty, just pushes item to top
		data[top] = item;
		actual = 1;
		return true;
	}

	if (!full()) { //if the stack is not full, actual gets incremented. If it is, then returns false
		actual++;
	} else {
		return false;
	}

	for (int i = max - 1; i >= 0; i--) { //loop that shifts all elements down so item can be pushed on
		if (i == 0) {
			data[top] = item;
			return true; //returns true when finished
		} else {
			data[i] = data[i - 1];
		}
	}

	actual--; //returns false and decrements actual if loop does not finish
	return false;

}

bool Stack::pop(char& item) { //function that pops the top element off of the stack

	if (empty()) { //if the stack is empty, just sets values to default and returns false
		data[top] = '\0';
		top = -1;
		return false;
	}

	item = data[top]; //stores top in item

	actual--; //actual is decremented

	for (int i = 0; i < actual + 1; i++) { //loop that shifts elements down until the new actual is reached
		data[i] = data[i + 1];
		if (i == actual) {
			data[i] = '\0';
			return true; //returns true and sets the empty data to null when the loop finishes
		}
	}

	actual++; //increments actual and returns false if loop doesn't finish
	return false;

}

bool Stack::empty() const { //checks if stack is empty

	if (actual == 0) { //if actual is 0, then returns true
		return true;
	} else return false;

}

bool Stack::full() const { //checks if stack is full

	if (actual == max) { //if actual is equal to max, then returns true
		return true;
	} else return false;

}

bool Stack::clear() { //clears the stack

	if (empty()) { //if stack is empty, returns false
		return false;
	}
	
	for (int i = 0; i < actual; i++) { //loops that sets each data member to the null character
		data[i] = '\0';
	}

	actual = 0; 

	top = -1; 

	return true;

}

bool Stack::operator==(const Stack& source) const { //checks to see if two stacks are equal to each other

	if (max != source.max) { //compares each data member and returns false if they are different
		return false;
	}

	if (actual != source.actual) {
		return false;
	}

	if (top != source.top) {
		return false;
	}

	for (int i = 0; i < actual; i++) {
		if (data[i] != source.data[i]) {
			return false;
		}
	}

	return true; //returns true if nothing is different

}

ostream& operator<<(ostream& os, const Stack& list) { //outputs the stack

	for (int i = 0; i < list.actual; i++) { //loop that outputs each item in the stack
		os << list.data[i];
	}

	return os;

}
