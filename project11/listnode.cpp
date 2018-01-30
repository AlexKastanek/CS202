#include <iostream>
#include <fstream>
#include "listnode.h"

using namespace std;

Node::Node(int a, Node* b) { //default constructor

	data = a;
	next = b;

}

ListNode::ListNode(int a) { //default constructor

	head = NULL;
	cursor = NULL;

}

ListNode::ListNode(const ListNode& source) { //copy constructor

	Node* tempCursor2 = source.head;

	Node* temp = new Node(tempCursor2->data, tempCursor2->next);

	head = temp;

	cursor = temp;

	Node* tempCursor1 = temp;

	while (tempCursor2->next != NULL) {
		tempCursor2 = tempCursor2->next;
		Node* temp = new Node(tempCursor2->data, tempCursor2->next);
		tempCursor1->next = temp;
		tempCursor1 = tempCursor1->next;
	}

	tempCursor1->next = NULL;

}

ListNode::~ListNode() { //destructor

	delete head;
	delete cursor;

}

bool ListNode::insertAfter(int item) { //inserts a value after where the cursor points and moves the cursor to that spot

	if (isFull()) {
		return false;
	}

	if (isEmpty()) {
		Node* tempStart = new Node(item, NULL);
		head = tempStart;
		cursor = tempStart;
		return true;
	}

	Node* temp = new Node(item, cursor->next);

	cursor->next = temp;

	cursor = cursor->next;

	return true;

}

bool ListNode::insertBefore(int item) { //inserts a value before where the cursor points and moves the cursor to that spot

	if (isEmpty()) {
		return false;
	}

	if (head == cursor) {
		Node* temp = new Node(item, cursor);
		head = temp;
		cursor = head;
		return true;
	}

	Node* tempCursor = head;

	while (tempCursor->next != cursor) {
		tempCursor = tempCursor->next;
	}

	Node* temp = new Node(item, cursor);

	tempCursor->next = temp;

	cursor = temp;

	return true;

}

bool ListNode::get(int& item) const { //gets the item that the cursor is pointing to

	if (isEmpty()) {
		return false;
	}

	item = cursor->data;

	return true;

}

bool ListNode::remove(int& item) { //removes the item that the cursor is pointing to

	if (isEmpty()) {
		return false;
	}

	Node* tempCursor = head;

	while (tempCursor->next != cursor) {
		tempCursor = tempCursor->next;
	}

	tempCursor->next = cursor->next;

	Node* temp = cursor;

	cursor = cursor->next;

	delete temp;

	return true;

}

void ListNode::clear() { //clears the list

	if (isEmpty()) {
		return;
	}

	Node* tempCursor = head;

	while (tempCursor->next != NULL) {
		tempCursor->data = 0;
		tempCursor = tempCursor->next;
	}

	cursor = NULL;

	head = NULL;

}

bool ListNode::goToBeginning() { //moves cursor to the beginning of the list

	if (isEmpty()) {
		return false;
	}

	cursor = head;

	return true;

}

bool ListNode::goToEnd() { //moves cursor to the end of this list

	if (isEmpty()) {
		return false;
	}

	while (cursor->next != NULL) {
		cursor = cursor->next;
	}

	return true;

}

bool ListNode::goToNext() { //moves cursor to the next position in the list

	if (isEmpty() || isFull() || cursor->next == NULL) {
		return false;
	}

	cursor = cursor->next;

	return true;

}

bool ListNode::goToPrior() { //moves cursor to the prior position in the list

	if (isEmpty() || cursor == head) {
		return false;
	}

	Node* tempCursor = head;

	while (tempCursor->next != cursor) {
		tempCursor = tempCursor->next;
	}

	cursor = tempCursor;

	return true;

}

bool ListNode::isEmpty() const { //checks to see if the list is empty

	if (head == NULL) {
		return true;
	} else return false;

}

bool ListNode::isFull() const { //checks to see if the list is full

	return false;

}

ListNode& ListNode::operator=(const ListNode& source) { //copies the sources list to the calling object

	clear();

	Node* tempCursor2 = source.head;

	Node* temp = new Node(tempCursor2->data, tempCursor2->next);

	head = temp;

	cursor = temp;

	Node* tempCursor1 = temp;

	while (tempCursor2->next != NULL) {
		tempCursor2 = tempCursor2->next;
		Node* temp = new Node(tempCursor2->data, tempCursor2->next);
		tempCursor1->next = temp;
		tempCursor1 = tempCursor1->next;
	}

	tempCursor1->next = NULL;

	return *this;

}

ostream& operator<<(ostream& os, const ListNode& source) { //outputs the list

	Node* cursor = source.head;

	while (cursor->next != NULL) {
		os << cursor->data;
		cursor = cursor->next;
	}

	os << cursor->data;

	return os;

}





