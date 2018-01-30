#include <iostream>
#include <fstream>
#include "queueN.h"

using namespace std;

Node::Node(int a, Node* b) { //paramaterized constructor

	data = a;
	next = b;

}

Queue::Queue(int a) { //default constructor

	front = NULL;
	rear = NULL;

}

Queue::Queue(const Queue& source) { //copy constructor

	front = source.front;
	rear = source.rear;

	Node* cursor1 = front;
	Node* cursor2 = source.front;

	while (cursor2->next != NULL) { //loop that sets each data member of the next node equal to the source
		cursor1->next = cursor2->next;
		cursor1 = cursor1->next;
		cursor2 = cursor2->next;
	}

	cursor1->next = cursor2->next;

}

Queue::~Queue() { //destructor

	delete front;
	delete rear;

}

Queue& Queue::operator=(const Queue& source) { //copies one queue into the calling object

	clear(); //clears the array first

	Node* cursor = source.front;

	while (cursor->next != NULL) { //loop that enqueues each data member from the source
		enqueue(cursor->data);
		cursor = cursor->next;
	}

	enqueue(cursor->data);

	return *this;

}

bool Queue::enqueue(int item) { //adds a value to the queue

	if (full()) { //if queue is full, returns false
		return false;
	}

	Node* temp = new Node(item, NULL); //allocates memory for new node

	if (rear == NULL) { //if this is the queue's first time being used, or the first time after being cleared/reset, then this statement sets front and rear to temp instead of just rear
		front = temp;
		rear = temp;
		return true;
	}

	rear->next = temp; //sets this node's next node to temp

	rear = temp; //sets rear to temp's location

	return true;

}

bool Queue::dequeue(int& item) { //pulls the first item that's queued up

	if (empty()) { //if queue is empty, resets front and rear to NULL and returns false
		front = NULL;
		rear = NULL;
		return false;
	}

	Node* temp;

	temp = front; //temp node stores where front is currently pointing

	front = front->next; //front is moved to its next value

	item = temp->data; //item gets data member stored in what was the front

	delete temp; //node is deleted

	return true;

}

bool Queue::empty() const { //returns true if front is equal to rear

	if (front == rear) {
		return true;
	} else return false;

}

bool Queue::full() const { //always returns false unless memory is full

	return false;

}

bool Queue::clear() { //clears the array of all data members and resets front and rear to NULL

	if (empty()) { //if the queue is empty, resets front and rear and returns false
		front = NULL;
		rear = NULL;
		return false;
	}

	Node* cursor = front; //cursor node to go through linked list

	while (cursor->next != NULL) { //loop that deletes and deallocates all nodes
		Node* temp = cursor;
		cursor = cursor->next;
		delete temp;
	}

	delete cursor;

	front = NULL; //resets and front and rear
	rear = NULL;

}

bool Queue::operator==(const Queue& source) const { //returns true if two queues are equal

	int count1 = 0, count2 = 0;

	Node* cursor1 = front;
	Node* cursor2 = source.front;

	while (cursor1->next != NULL) { //loop to determine size of calling object's queue
		count1++;
		cursor1 = cursor1->next;
	}
	count1++;

	while (cursor2->next != NULL) { //loop to determine size of source's queue
		count2++;
		cursor2 = cursor2->next;
	}
	count2++;

	if (count1 != count2) { //if the actual sizes are different returns false
		return false;
	}

	cursor1 = front; //cursors to go though each linked list
	cursor2 = source.front;

	while (cursor1->next != NULL) { //loop that compares the data members of each node
		if (cursor1->data != cursor2->data) { //returns false if the two data members differ
			return false;
		}
		cursor1 = cursor1->next;
		cursor2 = cursor2->next;
	}

	if (cursor1->data != cursor2->data) {
		return false;
	}

	return true;

}

ostream& operator<<(ostream& os, const Queue& source) { //outputs the queue

	Node* cursor = source.front; //cursor to go though linked list

	while (cursor->next != NULL) { //loop that outputs each data member
		os << cursor->data;
		cursor = cursor->next;
	}

	os << cursor->data;

	return os;

}





