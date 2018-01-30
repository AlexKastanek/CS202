#include <iostream>
#include <fstream>
#include "stackN.h"

using namespace std;

Node::Node(char a, Node* b) { //paramaterized constructor
	data = a;
	next = b;
}

Stack::Stack(int a) { //default constructor
	top = NULL;
}

Stack::Stack(const Stack& source) { //copy constructor

	Node* cursor = source.top;

	top = cursor;

	while (cursor->next != NULL) {
		cursor--;
		push(cursor->data);
	}

}

Stack::~Stack() { //destructor

	delete top;

}

Stack& Stack::operator=(const Stack& source) { //assignment operator that attempts to set two stacks equal to each other

	clear(); //clears the stack

	Node* cursor = source.top; 

	top = cursor;

	while (cursor->next != NULL) { //loop that sets each node equal to each other until the next node is NULL
		cursor--;
		push(cursor->data);
	}

	return *this;

}

bool Stack::push(char item) { //pushes a node onto the stack

	if (full()) { //if stack is full returns false
		return false;
	}

	Node* temp = new Node(item, top); //allocates a new node with parameters of the specified item and the next node which is top for now

	top = temp; //sets top equal to the newly allocated node

	return true;

}

bool Stack::pop(char& item) { //pops a node from the top of the stack

	if (empty()) { //if the stack is empty returns false
		return false;
	}

	Node* temp; //temp node created to store top node

	temp = top; //stores top node into temp

	item = temp->data; //stores the data from temp in item
	
	top = top->next; //moves top down to its next value

	delete temp;

}

bool Stack::empty() const { //checks to see if stack is empty

	if (top == NULL) { //if top is equal to NULL, returns true
		return true;
	} else return false;

}

bool Stack::full() const { //checks to see if stack is full

	return false; //always returns false assuming memory capacity isn't reached

}

bool Stack::clear() { //clears the stack

	if (empty()) { //if stack is empty returns false
		return false;
	}

	Node* cursor = top; 

	cursor--;

	while (cursor->next != NULL) { //loop that deletes each value until 
		Node* temp = cursor;
		cursor--;
		delete temp;
	}

	top = NULL;

	delete cursor;

	return true;

}

bool Stack::operator==(const Stack& source) const { //checks to see if two stacks equal each other

	if (top != source.top) {
		return false;
	}

	Node* cursor1 = top;
	Node* cursor2 = source.top;

	while (cursor2->next != NULL) { //loop that compares each data value in each node
		if (cursor1->data != cursor2->data) {
			return false;
		}
		cursor1--;
		cursor2--;
	}

	return true;

}

ostream& operator<<(ostream& os, const Stack& list) { //ouputs each data value in each node of the stack

	Node* cursor = list.top;

	while (cursor->next != NULL) {
		os << cursor->data;
		cursor--;
	}

	os << cursor->data;

	return os;

}


