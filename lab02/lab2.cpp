#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void checkArgNum(int);

void readAndPrint(const char*);

int main(int argc, char *argv[]) {

	try {
		checkArgNum(argc);
	} catch (const exception& msg) {
		cerr << msg.what() << endl;
		return 0;
	}

	try {
		readAndPrint(argv[1]);
	} catch (const exception& msg) {
		cerr << msg.what() << endl;
		return 0;
	}

	return 0;

}

void checkArgNum(int argNum) {

	if (argNum > 2 || argNum < 2) {
		throw invalid_argument("ERROR: Invalid number of arguments");
	}

	//return argNum;

}

void readAndPrint(const char* fileName) {

	char* arr = new char[100];

	ifstream fin;
	fin.open(fileName);

	if (!fin) {
		throw out_of_range("ERROR: Could not open file");
	}

	fin.getline(arr, 100);
	
	cout << arr;

	fin.close();

	delete[] arr;
	arr = NULL;

}
