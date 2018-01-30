#include <iostream>
#include <fstream>
using namespace std;

struct Pieces { //pieces holds the word and jump for each section in the given file's cipher
	char* word;
	int jump;
};

void get_bounds(char*, int&, int&); //gets the first two integers in the file to allocate the memory with arrays of those sizes

void get_input(Pieces*, char*, int, int, int&, int*); //gets all of the input from the file

void decrypt_code(Pieces*, int, int, int, int*); //deciphers the file and prints it out to screen

int str_len(char*); //finds the length of a string or character array and makes it a string

void str_concat(char*, char*, int, int, int&, int); //attempts to concatenate two strings together

int main() {

	Pieces* cipher;
	char* fileName = new char[21];
	int wordNum = 0, keyNum = 0, finalLength = 0;
	int* keys;

	cout << "Please enter the name of the file: ";
	cin >> fileName;

	get_bounds(fileName, wordNum, keyNum); //runs function to get wordNum and keyNum which are passed by reference

	cipher = new Pieces[wordNum]; //allocates memory for arrays in accordance to what happens in the get_bounds function
	keys = new int[keyNum];

	get_input(cipher, fileName, wordNum, keyNum, finalLength, keys); //gets all of the data from the file

	//cout << "function done2" << endl;

	//finalLength = finalLength + 1;
	//cout << finalLength << endl;

	//int* kptr = keys;
	//cout << keyNum << endl;
	//cout << *kptr << endl;
	/*for (int i = 0; i < keyNum; i++) {
		cout << *kptr << endl;
		kptr++;	
	}*/

	//delete[] kptr;
	//kptr = NULL;

	decrypt_code(cipher, finalLength, wordNum, keyNum, keys); //deciphers the code in the file

	delete[] fileName; //deallocates fileName and points the pointer to NULL
	fileName = NULL;
	
	Pieces* cptr = cipher; //deallocates every string in cipher
	for (int i = 0; i < wordNum; i++) {
		//cout << (*cptr).word << endl;
		delete[] (*cptr).word;
		cptr++;
	}
	cptr = NULL; //points cptr to NULL

	//delete[] cptr;
	//cptr = NULL;

	delete[] cipher; //deallocates cipher and points it to NULL
	cipher = NULL;
	//cptr = NULL;	

	delete[] keys; //deallocates keys and points it to NULL
	keys = NULL;

	//delete[] decoded;
	//decoded = NULL;

	return 0;

}

void get_bounds(char* fileName, int &wordNum, int &keyNum) { //gets the first two integers in the file

	ifstream fin;
	fin.open(fileName);

	fin >> wordNum;
	
	fin >> keyNum;

	fin.close();

}

void get_input(Pieces* cipher, char* fileName, int wordNum, int keyNum, int &finalLength, int* keys) { //gets all of the data from the file

	int a, b;

	ifstream fin;
	fin.open(fileName);

	fin >> a; //since the first two integers are already stored, the new values are thrown away into a and b variables which are never used
	//cipher = new Pieces[wordNum];
	//cout << wordNum << endl;

	fin >> b;
	//cout << keyNum << endl; debugging

	Pieces* cptr;
	cptr = cipher;

	for (int i = 0; i < wordNum; i++) { //gets every word and every jump
		int wordLength = 0;
		char* temp;
		temp = new char[20]; //allocates a temp array to determine the length
		fin >> temp;
		//cout << str_len(temp) << endl; debugging
		wordLength = str_len(temp); //calls string length to determine the length of the string held in temp
		finalLength = finalLength + wordLength;//increments finalLength by wordLength
		(*cptr).word = new char[wordLength]; //allocates memory for each indivual word in the cipher
		char* wptr = (*cptr).word;
		char* tptr = temp;
		for (int j = 0; j < wordLength; j++) { //sets values in word equal to temp
			*wptr = *tptr;
			wptr++;
			tptr++;
		}
		wptr = NULL; //sets the pointers to NULL
		tptr = NULL;
		//cout << (*cptr).word;
		//cptr++;
		fin >> (*cptr).jump; //gets jump
		//cout << " - " << (*cptr).jump << endl;
		delete[] temp;
		temp = NULL;
		cptr++; 
	}

	//cptr = cipher;
	
	/*for (int i = 0; i < wordNum; i++) {
		cout << (*cptr).word << endl;
		cptr++;
	}*/

	cptr = cipher; //resets cptr back to firts value in cipher

	//keys = new int[keyNum];

	int* kptr = keys;
	
	//cout << keyNum << endl;
	for (int i = 0; i < keyNum; i++) { //gets all of the keys in the file
		fin >> *kptr;
		//cout << *kptr << endl;
		kptr++;
	}

	kptr = keys;

	fin.close();

	//delete[] cptr;
	cptr = NULL;

	//delete[] kptr;
	kptr = NULL;

	//cout << "function done1" << endl;

}

void decrypt_code(Pieces* cipher, int finalLength, int wordNum, int keyNum, int* keys) { //decrypts the code that was obtained from the file

	Pieces* cptr = cipher;
	Pieces* optr = cipher;
	int* kptr = keys;
	char* decoded = new char[finalLength]; //allocates decoded to size finalLength 
	char* dptr = decoded;
	char* wptr;
	int wordLength = 0, oldWordLength = 0, newLength = 0, jumpVal = 0;

	/*for (int i = 0; i < finalLength; i++) {
		*dptr = '\0';
		dptr++;
	}*/

	dptr = decoded;

	for (int i = 0; i < keyNum; i++) { //loop that runs through every key
		//cout << "check 1" << endl;
		for (int j = 0; j < *kptr; j++) { //increments to the number of the specific key
			//cout << "check 2" << endl;
			//cout << (*cptr).word << endl;
			cptr++;
			//cout << (*cptr).word << endl;
		}
		while ((*cptr).jump != 0) { //increments and loops, if necessary, while jump is not zero
			//cout << "check 3" << endl;
			jumpVal = (*cptr).jump;
			//cout << "check 3 - " << jumpVal << endl;
			for (int k = 0; k < jumpVal; k++) {
				//cout << "check 4" << endl;
				cptr++;
				if (cptr == cipher + wordNum) { //loops the function around if cptr has gone through it all
					cptr = cipher;
				}
			}
		}
		if ((*cptr).jump == 0) { //if jump is zero then prints out the specific word the pointer is pointing, if str_concat was working it would have called that which would have stored the specific word in a final array, decoded.
			//cout << "check 5" << endl;
			wordLength = str_len((*cptr).word);
			oldWordLength = str_len((*optr).word);
			wptr = (*cptr).word;
			cout << (*cptr).word << " ";
			//cout << wordLength << endl;
			/*if (i == 0) {
				for (int k = 0; k < wordLength; k++) {
					*dptr = *wptr;
					dptr++;
					wptr++;
				}
				cout << "check init: " << decoded << endl;
			} else {
				//str_concat((*cptr).word, decoded, oldWordLength, wordLength, newLength, finalLength); //this is where str_concat would have been called
				//cout << "final: " << decoded << endl;
			}*/
		}
		//cout << "check 6" << endl;
		kptr++;
		optr = cptr;
		cptr = cipher;
	}

	cptr = cipher; //resets the pointers to original values
	wptr = (*cptr).word;
	kptr = keys;

	cout << endl; 

	delete[] decoded; //deallocates decoded and points it to NULL
	decoded = NULL;

	cptr = NULL;
	optr = NULL;
	dptr = NULL;
	wptr = NULL;
	kptr = NULL;

}

int str_len(char* str) {
	
	int length = 0;
	char* sptr = str;

	while (*sptr != '\0') {
		length++;
		sptr++;
	}

	length++;

	//delete[] sptr;
	sptr = NULL;

	return length;
	
}

void str_concat(char* newWord, char* decoded, int oldWordLength, int wordLength, int &newLength, int finalLength) { //this function attempts to concatenate two strings and store them into decoded but it is not functional

	char* wptr;
	char* nptr;

	wptr = decoded;

	cout << decoded << endl;

	for (int i = 0; i < (oldWordLength + newLength); i++) { //this should have incremented the decoded pointer to the location in the string where it would need to write to next
		cout << "check orig" << endl;
		wptr++;
	}
	
	nptr = newWord;
	
	for (int i = 0; i < wordLength; i++) { //this should have actually written the string onto decoded until the wordLength was reached
		cout << "check concat of " << *nptr << " onto " << *wptr << endl;
		*wptr = *nptr;
		cout << decoded << endl; //debugging
		wptr++;
		nptr++;
	}

	newLength = str_len(decoded);
	cout << "check length: " << newLength << endl;

	wptr = decoded;
	nptr = NULL;

}
