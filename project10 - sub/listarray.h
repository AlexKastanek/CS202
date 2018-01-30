#include <iostream>

using namespace std;

template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray<T>&);
    ~ListArray();

    bool insertBefore(const T&);
    bool insertAfter(const T&);
    bool get(T&) const;
    bool remove(T&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray<T>& operator = (const ListArray<T>&);

    template <typename S>
    friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};

template <typename T>
ListArray<T>::ListArray(int a) { //default constructor

	size = a;

	actual = 0;

	cursor = -1;

	data = new T[size];

}

template <typename T>
ListArray<T>::ListArray(const ListArray<T>& source) { //copy constructor

	size = source.size;

	actual = source.actual;

	cursor = source.cursor;

	for (int i = 0; i < actual; i++) {
		data[i] = source.data[i];
	}

}

template <typename T>
ListArray<T>::~ListArray() { //destructor

	size = 0;

	actual = 0;

	cursor = -1;

	delete[] data;

	data = NULL;

}

template <typename T>
bool ListArray<T>::insertBefore(const T& item) { //inserts a value before where the cursor points and moves the cursor to that spot

	if (isEmpty() || isFull()) {
		return false;
	}

	for (int i = actual - 1; i >= cursor; i--) {
		data[i + 1] = data[i];
	}

	data[cursor] = item;

	actual++;

	return true;

}

template <typename T>
bool ListArray<T>::insertAfter(const T& item) { //inserts a value after where the cursor points and moves the cursor to that spot

	if (isFull()) {
		return false;
	}

	if (isEmpty()) {
		cursor++;
		data[cursor] = item;
		actual++;
		return true;
	}

	for (int i = actual - 1; i > cursor; i--) {
		data[i + 1] = data[i];
	}

	cursor++;

	data[cursor] = item;

	actual++;

	return true;

}

template <typename T>
bool ListArray<T>::get(T& item) const { //gets the item that the cursor is pointing to

	if (isEmpty()) {
		return false;
	}

	item = data[cursor];

	return true;

}

template <typename T>
bool ListArray<T>::remove(T& item) { //removes the item that the cursor is pointing to

	if (isEmpty()) {
		return false;
	}

	item = data[cursor];

	if (actual == 1) {
		actual = 0;
		cursor = -1;
		return true;
	}

	for (int i = cursor; i < actual; i++) {
		data[i] = data[i + 1];
	}

	actual--;

	return true;

}

template <typename T>
void ListArray<T>::clear() { //clears the list

	actual = 0;

	cursor = -1;

}

template <typename T>
bool ListArray<T>::goToBeginning() { //moves cursor to the beginning of the list

	if (isEmpty()) {
		return false;
	}

	cursor = 0;

	return true;

}

template <typename T>
bool ListArray<T>::goToEnd() { //moves cursor to the end of this list

	if (isEmpty()) {
		return false;
	}

	cursor = actual - 1;

	return true;

}

template <typename T>
bool ListArray<T>::goToNext() { //moves cursor to the next position in the list

	if (isEmpty() || cursor == size - 1) {
		return false;
	}

	cursor++;

	return true;

}

template <typename T>
bool ListArray<T>::goToPrior() { //moves cursor to the prior position in the list

	if (isEmpty() || cursor == 0) {
		return false;
	}

	cursor--;

	return true;

}

template <typename T>
bool ListArray<T>::isEmpty() const { //checks to see if the list is empty

	if (actual == -1) {
		return true;
	} else return false;

}

template <typename T>
bool ListArray<T>::isFull() const { //checks to see if the list is full

	if (actual == size - 1) {
		return true;
	} else return false;

}

template <typename T>
ListArray<T>& ListArray<T>::operator=(const ListArray<T>& source) { //copies the sources list to the calling object

	clear();

	size = source.size;

	actual = source.actual;

	cursor = source.cursor;

	for (int i = 0; i < actual; i++) {
		data[i] = source.data[i];
	}

	return *this;

}

template <typename S>
ostream& operator << (ostream& os, const ListArray<S>& source) { //outputs the list

	for (int i = 0; i < source.actual; i++) {
		os << source.data[i];
	}

	return os;

}





