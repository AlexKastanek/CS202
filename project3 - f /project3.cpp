#include <iostream>
#include <fstream>
using namespace std;

struct Inventory {
	int year;
	char make[11];
	char model[11];
	float price;
	bool avail;
};

struct Agency {
	char name[11];
	int zip[5];
	Inventory carStats[5];
};

bool get_input(char*, Agency*);

int main() {

	Agency info[3];
	char fileName[21];
	char* filePtr;
	int userChoice;
	bool checkInput = 0;

	while (!checkInput) {
		cout << ("Please enter the name of the file you would to scan for input: ");
		cin >> fileName;
		filePtr = fileName;
		checkInput = get_input(fileName, info);
		if (!checkInput) {
			cout << ("Error: invalid input");
		}
	}

return 0;
}

bool get_input(char* fileName, Agency info) {
	Agency* aptr;
	//aptr = &info;
	cout << fileName << endl;
	ifstream fin;
	fin.open(fileName);
	aptr = (&info).name;
	while (aptr != '\0') {
		cout *aptr;
		*aptr++;
	}
	aptr = info.zip;
	while (aptr != '\0') {
		cout *aptr;
		*aptr++;
	}
	//cout << (*aptr).name << endl;
	//cout << (*aptr).zip << endl;
	fin.close();
	return 1;
}
