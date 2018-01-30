#include <iostream>
#include <fstream>
using namespace std;

struct Inventory { //struct to store the data of each car
	int year;
	char make[11];
	char model[11];
	float price;
	bool avail;
};

struct Agency { //struct to store the data of each agency
	char name[11];
	int zip[5];
	Inventory carStats[5];
};

void get_input(char*, Inventory*, Agency*); //function that gets input from the user

void print_data(Inventory*, Agency*); //function that prints all of the information for each agency and each car

void estimate_cost(Inventory*, Agency*, int&); //function that attempts to estimate the cost of a car for a specific agency

void most_exp(Inventory*, Agency*); //function that determines the price of the most expensive car

//I was not able to complete the print available function

int main() {
	
	Agency info[3];
	Inventory carStats[5];
	int carNum = 0;
	char fileName[21];
	int userChoice;

	//debugging:
	//cin >> fileName;

	/*cout << fileName << endl;
	ifstream fin;
	fin.open(fileName);
	fin >> (*iptr).name;
	cout << (*iptr).name;*/

	cout << ("Please enter the name of the file you would to scan for input: "); //gets the name of the file from the user
	cin >> fileName;
	get_input(fileName, carStats, info); //uses the file name to get input from that file

	do {

		cout << endl << "===========================================" << endl; //prints menu for user
		cout << "Please choose on of the following options: " << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1) Print all of the data" << endl;
		cout << "2) Estimate car rental cost" << endl;
		cout << "3) Find the most expensive car" << endl;
		cout << "4) Print the available cars" << endl;
		cout << "5) Exit program" << endl;
		cout << "-------------------------------------------" << endl;
		//cout << "===========================================" << endl;
		userChoice = 0;
		cin >> userChoice; //prompts the user for a menu option

		switch (userChoice) {
			case 1: 
				cout << "======================" << endl;
				cout << "Print all of the data:" << endl;
				cout << "======================" << endl;
				print_data(carStats, info);
				break;
			case 2:
				cout << "========================" << endl;
				cout << "Estimate car rental cost" << endl;
				cout << "========================" << endl;
				estimate_cost(carStats, info, carNum);
				break;
			case 3:
				cout << "====================" << endl;
				cout << "Print most expensive" << endl;
				cout << "====================" << endl;
				most_exp(carStats, info);
				break;
			case 4:
				cout << "unavailable" << endl;
				break;
			case 5:
				//cout << (*carStats).year << endl;
				//cout << info << endl;
				//cout << carStats << endl;
				userChoice = 5;
				break;
			default:
				cout << "Error: Invalid entry" << endl;
				userChoice = 0;
		}
	} while (userChoice != 5);

	//debugging:
	/*char *nptr = (*info).name;
	while (*nptr != '\0') {
		cout << *nptr;
		nptr++;
	}
	cout << endl;
	int *zptr = (*info).zip;
	for (int i = 0; i < 5; i++) {
		cout << *zptr;
		zptr++;
	}
	cout << endl;*/

	//cout << (*info).name << endl;
	//cout << (*carStats).year << endl;

	return 0;
}

void get_input(char* fileName, Inventory* carStats, Agency* info) { //function that scans a user-entered file for input

	ifstream fin;
	fin.open(fileName);
	Agency* iptr = info; //pointer that points to the first value in info
	Inventory* cptr = carStats; //pointer that points to the first value in carStats
	for (int i = 0; i < 3; i++) { //this loops runs until all three agencies have been scanned
		//Agency* iptr = info;
		fin >> (*iptr).name;
		//cout << (*iptr).name << endl; //debugging
		iptr++;
		int* zptr = (*iptr).zip;
		for (int j = 0; j < 6; j++) { //loop converts chars to array of ints to store the values for zip
			int current;
			current = (int)fin.get();
			//cout << current << endl; //debugging
			//cout << current - 48 << endl;
			if (j > 0) {
				//iptr++;
				*zptr = current - 48; //converts by subtracting the ASCII value of a number by 48 to get the integer value
				//zptr++;
				//cout << *zptr; //debugging
				//(info).zip = zptr*;
				zptr++;
			}
		}
		//cout << endl;
		iptr++;
		//cptr = carStats;
		for (int j = 0; j < 5; j++) { //this loop runs until all 5 inventories have been scanned
			//cptr = carStats;
			fin >> (*cptr).year;
			//cout << (*cptr).year << endl; //all of these comments are for debugging purposes
			cptr++;
			fin >> (*cptr).make;
			//cout << (*cptr).make << endl;
			cptr++;
			fin >> (*cptr).model;
			//cout << (*cptr).model << endl;
			cptr++;
			fin >> (*cptr).price;
			//cout << (*cptr).price << endl;
			cptr++;
			fin >> (*cptr).avail;
			//cout << (*cptr).avail << endl;
			cptr++;
		}
		//cptr = carStats;
		iptr++;
	}
	//cout << (*aptr).name << endl;
	//cout << (*aptr).zip << endl;
	fin.close();
	iptr = info; //resetting the pointers back to their original spots
	cptr = carStats;
	//cout << (*cptr).year << endl;

}

void print_data(Inventory* carStats, Agency* info) {//function that prints all of the data scanned from the file

	Agency* iptr = info; 
	Inventory* cptr = carStats;
	for (int i = 0; i < 3; i++) { //loop runs until all values in all three agencies have been printed
		cout << (*iptr).name << " ";
		iptr++;
		int* zptr = (*iptr).zip;
		for (int j = 0; j < 5; j++) { //loop runs until array of integers has been printed
			cout << *zptr;
			zptr++;
		}
		cout << endl;
		iptr++;
		//cptr = (*iptr).carStats;
		for (int j = 0; j < 5; j++) { //loop runs until all values in all five inventories have been printed
			cout << (*cptr).year << " ";
			cptr++;
			cout << (*cptr).make << " ";
			cptr++;
			cout << (*cptr).model << " ";
			cptr++;
			cout << "$" << (*cptr).price << " per day ";
			cptr++;
			cout << "Available: ";
			if ((*cptr).avail == true) {
				cout << "true" << endl;
			} else cout << "false" << endl;
			cptr++;
		}
		cout << endl;
		iptr++;
	}
	iptr = info; //resetting the pointers back to their original positions
	cptr = carStats;
	//cout << (*cptr).year << endl;

}

void estimate_cost(Inventory* carStats, Agency* info, int &userCar) {//function that attempts to determing how expensive a specific car is

	int userAgency;
	float cost;
	cout << "Please enter the number of the agency of your choice: "; //promting user for number of agency and number of car
	cin >> userAgency;
	cout << "Please enter the number of a car in the agency you chose: ";
	cin >> userCar;
	Agency* iptr = info;
	Inventory* cptr = carStats;
	for (int i = 0; i < (userAgency - 1); i++) { //loop to increment pointer until the user-defined agency has been reached
		//cout << (*iptr).name << endl;
		iptr++;
		iptr++;
		//if (i != (userAgency - 1)) {
		iptr++;
		//}
	}
	cptr = (*iptr).carStats; //points to where last pointer left off
	//cout << (*cptr).year << endl; //debugging
	for (int j = 0; j < (userCar); j++) { //loop to increment pointer until the user-defined car has been reached
		cptr++;
		cptr++;
		cptr++;
		if (j == (userCar - 1)) { //once the user-defined car is reached, cost gets the price of the car
			cost = (*cptr).price;
		}
		cptr++;
		cptr++;
	}
	//cost = (*cptr).price;
	/*for (int j = 0; j < (5 - userCar); j++) {
	cptr++;
	}
	for
	iptr++;*/
	cout << "Estimated car rental cost: " << cost << endl; //prints the cost to screen
	iptr = info; //resetting back to original positions
	cptr = carStats;

}

void most_exp(Inventory* carStats, Agency* info) { //prints the price of the most expensive car

	Agency* iptr = info;
	Inventory* cptr = carStats;
	int agencyNum, carNum, expYear;
	//char expMake[11], expModel[11];
	float compare = 0; //compare will eventually get the highest value, and is compared to the current value, it is initialized at 0
	float current;

	for (int i = 0; i < 3; i++) { //loops through all three agencies
		iptr++;
		iptr++;
		//cout << (*cptr).year << endl;
		for (int j = 0; j < 5; j++) { //loops through all five cars for each agency
			cptr++;
			cptr++;
			cptr++;
			current = (*cptr).price; //current gets the price the loop is currently on
			if (current > compare) { //compares current and compare
				compare = current;
				agencyNum = i + 1; //these integers get the numbers of the agency and the car that the highest price was in
				carNum = j + 1;
			}
			cptr++;
			cptr++;
		}
		iptr++;
	}

	//below was my attempt at printing the year, make, and model of the car associated with the most expensive price
	//cout <<	"The most expensive car is the " << expMake << expModel << " at $" << compare << " per day." << endl;

/*	iptr = info;
	cptr = carStats;

	for (int i = 0; i < agencyNum; i++) {
		iptr++;
		iptr++;
		if (i == agencyNum - 1) {
			for (int j = 0; j < carNum; j++) {
				if (j == carNum - 1) {
					expYear = (*cptr).year;
					cptr++;
					expMake = (*cptr).make;
					cptr++;
					expModel = (*cptr).model;
					cptr++;
					cptr++;
				} else {
					for (int k = 0; k < 5; k++) {
						cptr++;
					}
				}
			}
		}
		iptr++;
	}

	cout <<	"The most expensive car is the " << expMake << expModel << " at $" << compare << " per day." << endl;*/

	cout << "The most expensive car is $" << compare << endl;

	iptr = info; //resetting the pointers back to default
	cptr = carStats;

}		
