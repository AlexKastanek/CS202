#include <iostream>
#include "String.h"

using namespace std;

//this file is the source code for the header file below

/*class String{

public:
	void initialize(char *);
	void deallocate();

	void copy(const String&);
	int length();
	void concat(const String&);
	int compare(const String&);

	void print();

private:
	char * buffer;
	int wordLength;
};*/

void String::initialize(char* temp) { //function that initializes and allocates buffer using the temp array passed to the function and gets the length of that array

	//delete[] buffer; error checking
	//buffer = NULL;

	wordLength = 0;
	char* tptr = temp;

	//loop that increments wordLength until pointer hits a null character
	while (*tptr != '\0') {
		//cout << *tptr << endl; debugging
		wordLength++;
		tptr++;
	}

	//wordLength++; error checking

	//cout << wordLength << endl; debugging

	//allocating buffer to size wordLength plus room for NULL character
	buffer = new char[wordLength + 1];

	//loop that copies the temp array into buffer
	tptr = temp;
	char* bptr = buffer;
	for (int i = 0; i < wordLength; i++) {
		*bptr = *tptr;
		tptr++;
		bptr++;
	}

	//resetting tptr back to its original position
	tptr = temp;

	//incrementing pointer and inserting null character in extra space
	bptr++;
	*bptr = '\0';

	//resetting bptr back to its original position
	bptr = buffer;

	//cout << buffer << endl; debugging

	//delete[] temp; error checking
	//temp = NULL;

	//sets tptr to NULL
	tptr = NULL;

}

void String::deallocate() { //function that deallocates the buffer array and points the pointer to NULL

	delete[] buffer;
	buffer = NULL;
	//bptr = NULL;

}

void String::copy(const String &source) { //function that copies the parameter into the object's buffer

	//deallocates buffer and sets its pointer to NULL
	delete[] buffer; 
	buffer = NULL;

	//the word length of the object's buffer is now equal to the word length of the source's buffer
	wordLength = source.wordLength;
	
	//reallocates buffer to new wordLength and adds space for null character
	buffer = new char[wordLength + 1];

	//loop that copies source's buffer into object's buffer
	char* sptr = source.buffer;
	char* bptr = buffer;
	for (int i = 0; i < wordLength; i++) {
		*bptr = *sptr;
		sptr++;
		bptr++;
	}
	
	//resetting sptr back to original position
	sptr = source.buffer;

	//increments pointer and inserts null character
	bptr++;
	*bptr = '\0';

	//resetting bptr back to original position
	bptr = buffer;

	//cout << buffer << endl; debugging

	//sets sptr to NULL
	sptr = NULL;

}

int String::length() { //function that returns wordLength

	return wordLength;

}

void String::concat(const String &source) { //function that concatenates source's buffer onto the object's buffer

	//sets new word length to the length of the object's buffer plus the source's buffer and allocates accordingly
	int newLength = wordLength + source.wordLength;
	char* temp = new char[wordLength];

	//loop that stores buffer in a temp array
	char* tptr = temp;
	char* bptr = buffer;
	for (int i = 0; i < wordLength; i++) {
		*tptr = *bptr;
		tptr++;
		bptr++;
	}

	//resetting bptr back to original position
	bptr = buffer;

	//deallocates buffer and sets pointer to NULL
	delete[] buffer;
	buffer = NULL;
	//bptr = NULL;

	//reallocates buffer to the new length and leaves room for the NULL character
	buffer = new char[newLength + 1];

	//loop that stores orginal characters in buffer
	tptr = temp;
	bptr = buffer;
	for (int i = 0; i < wordLength; i++) {
		*bptr = *tptr;
		tptr++;
		bptr++;
	}

	//resetting tptr back to its original position
	tptr = temp;

	//deallocates temp array
	delete[] temp;
	temp = NULL;
	//tptr = NULL;

	//loop that adds source's buffer onto the object's newly sized buffer
	char* sptr = source.buffer;
	for (int i = 0; i < (source.wordLength); i++) {
		*bptr = *sptr;
		sptr++;
		bptr++;
	}

	//resetting sptr back to its original position
	sptr = source.buffer;

	//increments bptr and sets it to null character
	bptr++;
	*bptr = '\0';

	//resetting bptr back to its original position
	bptr = buffer;

	//sets wordLength equal to the new length
	wordLength = newLength;

	//cout << buffer << endl; debugging

	//delete[] buffer; error checking
	//buffer = NULL;

	//sets sptr to NULL
	sptr = NULL;

}

int String::compare(const String &source) { //function that compares the alphabetical values of the object's buffer and the source's buffer, returns a -1 if the source's buffer is less than the object's buffer, a 0 if they are equal, and a 1 if the source's buffer is greater than the object's buffer

	int charValue, sourceValue = 0, bufValue = 0, finValue;
	
	//loop gets the alphabetical value of the source's buffer
	char* sptr = source.buffer;
	while (*sptr != '\0') {
		charValue = (int) *sptr;
		sourceValue = sourceValue + charValue;
		sptr++;
	}
	
	//resetting sptr back to its original position
	sptr = source.buffer;

	//cout << sourceValue << endl; debugging

	//loop gets the alphabetical value of the object's buffer
	char* bptr = buffer;
	while (*bptr != '\0') {
		charValue = (int) *bptr;
		bufValue = bufValue + charValue;
		bptr++;
	}
	
	//resetting bptr back to its orginal position
	bptr = buffer;

	//cout << bufValue << endl; debugging

	//if loop that tests which value is greater than the other and returns either a -1, 0, or 1
	if (sourceValue < bufValue) {
		finValue = -1;
	} else if (sourceValue == bufValue) {
		finValue = 0;
	} else if (sourceValue > bufValue) {
		finValue = 1;
	}

	return finValue;

}

void String::print() { //function that prints the object's buffer

	cout << buffer << endl;

}
