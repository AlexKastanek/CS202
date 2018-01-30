#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<class T>
class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack&);
                ~Stack();
                Stack& operator=(const Stack&);
                bool push(T item);
                bool pop(T& item);
                bool empty() const;
                bool full() const;
                bool clear();
				bool operator==(const Stack&) const;
				template<typename U>
                friend ostream& operator<<(ostream& os, const Stack<U>& list);
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                T data;
};

//#include "stack.cpp"


template<typename T>
Stack<T>::Stack(int a) { //default constructor with value of max set to 10 if no parameters are given

	max = a;
	top = -1;
	data = new T[max];

}

template<typename T>
Stack<T>::Stack(const Stack& source) { //copy constructor

	max = source.max;
	top = source.top;
	data = new T[max];
	for (int i = 0; i < max; i++) {
		data[i] = source.data[i];
	}

}

template<typename T>
Stack<T>::~Stack() { //destructor

	top = -1;
	delete[] data;
	data = NULL;

}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& source) { //assignment operator function assigns each value in the calling class to the source

	clear();
	delete[] data;
	data = NULL;

	max = source.max;
	
	if (source.empty()) {
		top = -1;
	} else top = 0;

	data = new T[source.max];

	for (int i = 0; i < top; i++) {
		data[i] = source.data[i];
	}

	return *this;

}

template<typename T>
bool Stack<T>::push(T item) { //function that pushes a specified element onto the stack

	if (full()) { //if stack is full returns false
		return false;
	}

	top++; //increments top

	data[top] = item; //places new item on top

	return true;

}

template<typename T>
bool Stack<T>::pop(T& item) { //function that pushes the top element off of the stack

	if (empty()) { //if stack is empty returns false
		return false;
	}

	item = data[top]; //stores top in item

	data[top] = default(T); //sets top to null character

	top--; //decrements top

	return true;

}

template<typename T>
bool Stack<T>::empty() const { //checks if stack is empty

	if (top == -1) { //returns true if top is -1
		return true;
	} else return false;

}

template<typename T>
bool Stack<T>::full() const { //checks if stack is full

	if (top == max - 1) { //returns true if top is equal to the max number of items - 1
		return true;
	} else return false;

}

template<typename T>
bool Stack<T>::clear() { //clears the stack

	if (empty()) { //if the stack is empty returns false
		return false;
	}

	for (int i = 0; i < max; i++) { //loop that sets each item in the stack to null
		data[i] = default(T);
	}

	top = -1; //sets top back to its default value

	return true;

}

template<typename T>
bool Stack<T>::operator==(const Stack& source) const { //checks to see if two stacks are equal

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

template<typename U>
ostream& operator<<(ostream& os, const Stack<U>& list) { //outputs the data within the stack

	for (int i = list.top; i >= 0; i--) {
		os << list.data[i];
	}

	return os;

}






template<typename T> 
void printStack(Stack<T> stack, int stackSize)
{
	// declare variables
	T item;

	// loop and print the stack with formatting
	for(int i = 0; i < stackSize; i++)
	{
		// if an item has been popped off the stack
		if(stack.pop(item))
		{
			// print the top of the stack
			if(i == 0)
				cout << "[" << item << "] ";

			// print other stack items
			else
				cout << item << " ";
		}
		// print empty stack
		else if(i == 0)
		{
			cout << "[empty stack] ";
		}
	}
	cout << endl;
}


int main()
{
	// declare variables
	int testItem;
	string stringItem;
	Stack <string> stringStack (3);
	Stack <int> intStack (5);

	// print test name
    cout << endl << endl << "Integer Stack: " << endl;

    // push 0 through 5
    for(int i = 0; i < 5; i++)
    {
    	intStack.push(i);
    }

   	cout << "Testing Int Stack Insertion Operator: " << intStack << endl;

   	intStack.clear();

	// test integer stack
	intStack.push(1);
	printStack(intStack, 5);

	intStack.push(2);
	printStack(intStack, 5);

	intStack.pop(testItem);
	printStack(intStack, 5);

	intStack.push(5);
	printStack(intStack, 5);

	intStack.push(4);
	printStack(intStack, 5);



	// print test name
	cout << endl << endl << "String Stack: " << endl;

	// push a through c
    stringStack.push("a");
    stringStack.push("b");
    stringStack.push("c");


   	cout << "Testing String Stack Insertion Operator: " << stringStack << endl;

   	stringStack.clear();

	// test string stack
	stringStack.push("orange");
	printStack(stringStack, 3);

	stringStack.pop(stringItem);
	printStack(stringStack, 3);

	stringStack.push("dog");
	printStack(stringStack, 3);

	stringStack.push("apple");
	printStack(stringStack, 3);

	stringStack.pop(stringItem);
	printStack(stringStack, 3);

	stringStack.push("cat");
	printStack(stringStack, 3);

	cout << endl << endl;


	// end program
	return 0;
}
