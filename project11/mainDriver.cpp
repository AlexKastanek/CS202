#include <iostream>
#include <fstream>
#include "listarray.h"
#include "listnode.h"

using namespace std;

void sort(int*, int); //function that sorts the data file

bool search(const int*, int, int); //function that searches to see if a user-specified number exists

int fibonacci(int); //function that outputs the result of a user-defined value that represents the place in a fibonacci sequence

int main() {

	int entrySearch, entryFib;
	int* data = new int[10]; //file is assumed to have 10 different integer values 
	ListNode unsorted;
	ListArray sorted(10);
	ifstream fin;

	fin.open("data");

	for (int i = 0; i < 10; i++) { //gets input from the file
		fin >> data[i];
	}

	//debugging
	/*for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}*/ 

	//cout << endl;

	for (int i = 0; i < 10; i++) { //stores data in an unsorted list
		unsorted.insertAfter(data[i]);
	}

	//cout << unsorted << endl; debugging

	sort(data, 10); //sorts the list

	//debugging
	/*for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}

	cout << endl;*/

	for (int i = 0; i < 10; i++) { //stores sorted data in a sorted list
		sorted.insertAfter(data[i]);
	}

	//cout << sorted << endl; debugging

	cout << "Please enter the number you would like to search for: ";

	cin >> entrySearch; //gets the number the user would like to search for

	if (search(data, 10, entrySearch)) { //prints the number exists if the function returns true and otherwise if it returns false
		cout << "This number exists" << endl;
	} else cout << "This number does not exist" << endl;

	cout << "Please enter the number you would like to calculate in a Fibonacci sequence: ";

	cin >> entryFib; //gets the place in a fibonacci sequence the user would like to search for

	cout << fibonacci(entryFib) << endl; //prints the value of that place

	return 0;

}

void sort(int* source, int num) { //uses a bubble sort to sort the data in the file

	bool swap = true;

	while (swap) {
		swap = false;
		for (int i = 0; i < (num - 1); i++) {
			if (source[i] > source[i + 1]) {
				int temp = source[i];
				source[i] = source[i + 1];
				source[i + 1] = temp;
				swap = true;
			}
		}
	}
}

bool search(const int* source, int num, int val) { //recursive function that uses a binary method to search for a specific value in a list of integers

	int divNum = num / 2; //divides the list into 2

	//error checking and debugging
	/*if ((num % 2) == 0) {
		divNum = num / 2;
	} else divNum = (num / 2) + 1;*/
	//cout << source[divNum] << endl;

	if (source[divNum] == val) { //if the divided number is the value then it returns true
		return true;
	}

	if (divNum == 0) { //if divided number is 0 then returns false, this means it cannot be divided anymore
		return false;
	}

	int* divSource = new int[divNum]; //allocating memory to store new array that is cut in half

	if (source[divNum] > val) { //if the divided number is greater than the value then the lower half of the original array is stored in the new one
		for (int i = 0; i < divNum; i++) {
			divSource[i] = source[i];
		}
	} else { //if the divided number is less than the value then the larger half of the original array is stored in the new one
		int j = 0;
		for (int i = divNum; i < num; i++) {
			divSource[j] = source[i];
			j++;
		}
		divNum = j; //sets the divided number to the value of the remaining difference of numbers so no value gets left out
	}

	return search(divSource, divNum, val); //returns the value of another calling of the functions if none of the conditions were met

}

int fibonacci(int val) { //recursive functions that determines that value of a fibonacci sequence

	if (val == 0) {
		return 0;
	} else if (val == 1) {
		return 1;
	} else return fibonacci(val - 1) + fibonacci(val - 2); //the next value in the fibonacci sequence is determined by adding the current value and the last value, so recursively adding the value 2 positions before the current one as well as 1 position away will eventually evaluate all values until 0 is reached

}

