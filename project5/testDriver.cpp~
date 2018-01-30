#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int word_length(char*); //returns the size of a word

int main() {
	
	//declaring variables and allocating memory for arrays
	ifstream fin;
	String firstTest;
	String secondTest;
	String firstWord;
	String secondWord;
	String* words = new String[10];
	String* wptr = words;
	char* testTemp = new char[0];
	char* fileTemp = new char[20];
	char* wordTemp = new char[20];
	char* fileName;
	//char* word;
	int fileLength, compValue;

	//getting input from the user
	cout << "Please enter the name of the file you would like scanned: ";
	cin >> fileTemp; //storing fileName into a temp array

	fileLength = word_length(fileTemp); //calling word_length function to determine the length of the fileName
	//cout << fileLength << endl; debugging

	fileName = new char[fileLength]; //allocating fileName to size fileLength

	//copying what's stored in fileTemp to fileName
	char* tptr = fileTemp;
	char* fptr = fileName; 
	for (int i = 0; i < fileLength; i++) {
		*fptr = *tptr;
		fptr++;
		tptr++;
	}
	//cout << fileName << endl; debugging

	//testing of String class begins
	cout << "-------------------------------------" << endl;
	cout << "Initialize and print function test: " << endl;

	//initializing firstTest using blank array
	firstTest.initialize(testTemp);

	//initializing secondTest using blank array
	secondTest.initialize(testTemp);

	fin.open(fileName);

	//storing the first word in the file in temp array
	fin >> wordTemp;

	//initializing the first word using the temp array
	firstWord.initialize(wordTemp);

	//deallocating the temp array
	delete[] wordTemp;
	wordTemp = NULL;

	//printing the first word
	firstWord.print();

	//reallocating the temp array to be used with the second word
	wordTemp = new char[20];

	//storing second word in the file in temp array
	fin >> wordTemp;

	//initializing the second word using the temp array
	secondWord.initialize(wordTemp);

	//delete[] wordTemp; error checking
	//wordTemp = NULL;

	//printing the second word
	secondWord.print();
	
	//loop that deallocates the temp array, reallocates the temp array, initializes every word in the words array and then prints that word
	for (int i = 0; i < 10; i++) {
		delete[] wordTemp;
		wordTemp = NULL;
		wordTemp = new char[20];
		fin >> wordTemp;
		(*wptr).initialize(wordTemp);
		(*wptr).print();
		wptr++;
		//delete[] wordTemp;
		//wordTemp = NULL;
	}
	//resetting wptr back to original position
	wptr = words;

	cout << "-------------------------------------" << endl;
	cout << "Compare function test: " << endl;

	//calls compare function in String class to compare the alphebetical value of two words
	compValue = firstWord.compare(secondWord);

	//if statement that prints the result of the compare function
	if (compValue == -1) {
		cout << "greater value: " << endl;
		firstWord.print();
	} else if (compValue == 0) {
		cout << "the two words are equal:" << endl;
		firstWord.print();
		secondWord.print();
	} else if (compValue == 1) {
		cout << "greater value: " << endl;
		secondWord.print();
	}

	cout << "-------------------------------------" << endl;
	cout << "First copy function test: " << endl;

	//copies the first word in the file to an empty array
	firstTest.copy(firstWord);

	//prints the copied word
	firstTest.print();

	cout << "-------------------------------------" << endl;
	cout << "First concat function test: " << endl;

	//concatenates the second word onto the copied first word
	firstTest.concat(secondWord);

	//prints the concatenated word
	firstTest.print();

	cout << "-------------------------------------" << endl;
	cout << "First length function test: " << endl;

	//prints the new length of the once empty array
	cout << firstTest.length() << endl;

	cout << "-------------------------------------" << endl;
	cout << "Second copy function test: " << endl;

	//copies the third word in the file to an empty array
	secondTest.copy(*wptr);

	//prints the copied word
	secondTest.print();

	cout << "-------------------------------------" << endl;
	cout << "Second concat function test (array): " << endl;

	//increments where wptr points to
	wptr++;

	//loop that concatenates two words onto the copied word, I receive a strange error when I try to concatenate all of the words. It works but the program ends with an error that states "double free or corruption" I was not able to fix the error
	for (int i = 1; i < 3; i++) {
		//wptr++;
		secondTest.concat(*wptr);
		wptr++;
	}

	//resetting wptr back to its original position
	wptr = words;

	//prints the concatenated word
	secondTest.print();

	cout << "-------------------------------------" << endl;
	cout << "Second length function test: " << endl;

	//prints the new length of the once empty array
	cout << secondTest.length() << endl;

	//deallocates the space needed to hold firstWord
	firstWord.deallocate();

	//deallocates the space needed to hold secondWord
	secondWord.deallocate();

	//loop that deallocates each word in the words array
	for (int i = 0; i < 10; i++) {
		(*wptr).deallocate();
		wptr++;
	}

	//resetting wptr back to its original position
	wptr = words;

	fin.close();

	//deallocates space needed to hold firstTest
	firstTest.deallocate();

	//deallocates space needed to hold secondTest
	secondTest.deallocate();

	//deallocates every array and sets all pointers to NULL
	delete[] words;
	words = NULL;
	wptr = NULL;
	delete[] testTemp;
	testTemp = NULL;
	delete[] fileTemp;
	fileTemp = NULL;
	delete[] wordTemp;
	wordTemp = NULL;
	tptr = NULL;
	delete[] fileName;
	fileName = NULL;
	fptr = NULL;

return 0;
}

int word_length(char* word) { //function that determines the length of a word
	
	int length = 0;
	char* wptr = word;

	//loop that increments length until pointer hits a null character
	while (*wptr != '\0') {
		length++;
		wptr++;
	}

	wptr = NULL;

	return length;
	
}

