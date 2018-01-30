#include <iostream>
#include <fstream>
#include "queue.h"

using namespace std;

Queue::Queue(int a) { //default constructor

	max = a;
	front = 0;
	rear = -1;
	data = new int[max];

}

Queue::Queue(const Queue& source) { //copy constructor

	max = source.max;
	front = source.front;
	rear = source.rear;
	data = new int[max];
	for (int i = 0; i < max; i++) {
		data[i] = source.data[i];
	}

}

Queue::~Queue() { //destructor

	clear();
	delete[] data;
	data = NULL;

}

Queue& Queue::operator=(const Queue& source) { //copies one queue into the calling object

	clear(); //clears array of all data
	delete[] data;
	data = NULL;

	max = source.max; //copying variables from source queue
	front = source.front;
	rear = source.rear;
	data = new int[max];
	for (int i = 0; i < max; i++) {
		data[i] = source.data[i];
	}

	return *this; //returns pointer to the calling object

}

bool Queue::enqueue(int item) { //adds an item to the queue

	if (full()) { //if the queue is full, returns false
		return false;
	}

	rear++; //rear increments and item is placed in rear's location

	data[rear] = item;

	return true;

}

bool Queue::dequeue(int& item) { //pulls the first item that's queued up (the first one that was added to the queue)

	if (empty()) { //if the queue is empty, returns false
		return false;
	}

	item = data[front]; //item gets what is currently stored in the front

	for (int i = 0; i < rear; i++) { //loop that shifts everything down
		data[i] = data[i + 1];
	}

	data[rear] = 0; //what was stored in rear now is 0

	rear--; //rear decrements and now stores the same value it used to

	return true;

}

bool Queue::empty() const { //if rear is negative one, then the queue is empty

	if (rear == -1) {
		return true;
	} else return false;

}

bool Queue::full() const { //if rear is equal to the number of possible numbers, then the queue is full

	if (rear == max - 1) {
		return true;
	} else return false;

}

bool Queue::clear() { //clears the queue of all values

	if (empty()) { //if the queue is empty, returns false
		return false;
	}

	for (int i = rear; i >= 0; i--) { //loop that clears all values
		data[i] = 0;
		rear--;
	}

	return true;

}

bool Queue::operator==(const Queue& source) const { //compares two queues and returns true if they are equal

	if (max != source.max) { //each if statement compares individual members of each queue and returns false if any are different
		return false;
	}

	if (rear != source.rear) {
		return false;
	}

	for (int i = 0; i < rear + 1; i++) {
		if (data[i] != source.data[i]) {
			return false;
		}
	}

	return true;

}

ostream& operator<<(ostream& os, const Queue& source) { //outputs all data in the queue

	for (int i = source.front; i < source.rear + 1; i++) {
		os << source.data[i];
	}

	return os;

}





