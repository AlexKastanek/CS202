#include <iostream>
#include <fstream>
#include "Agency.h"

using namespace std;

int main() {

	Agency inv, sortMake, sortPrice; //3 separate Agency objects to avoid problems with sorting the orginal object
	char* fileName = new char[20];
	char* userSearch;
	int carNum, dayNum, userChoice;

	cout << "Enter file name: "; //getting file name from user
	cin >> fileName;

	inv.readInData(fileName); //calls readInData function to get the data from the specified file; stores in inv
	sortMake.readInData(fileName); //stores data in sortMake
	sortPrice.readInData(fileName); //stores data in sortPrice

	do { //loops until user enters the exit program command
		cout << "===========================================================" << endl;
		cout << "Please choose one of the following options: " << endl;
		cout << "1) Print all information" << endl;
		cout << "2) Print information of available cars" << endl;
		cout << "3) Print information of most expensive car" << endl;
		cout << "4) Estimate cost of certain car over certain number of days" << endl;
		cout << "5) Sort all cars alphabetically by make" << endl;
		cout << "6) Sort all cars numerically by price" << endl;
		cout << "7) Search for information on a specific make" << endl;
		cout << "8) Exit program " << endl;
		cin >> userChoice;

		switch (userChoice) {
			case 1:
				inv.print(); //calls print function
			break;
			case 2:
				inv.printAvailableCars(); //calls print available function
			break;
			case 3:
				inv.findMostExpensive(); //calls find most expensive function
			break;
			case 4:
				cout << "what car would you like to calculate? "; 
				cin >> carNum; //gets the car number from the user
				cout << "how many days? ";
				cin >> dayNum; //gets the day number from the user
				cout << inv.estimateCost(carNum, dayNum) << endl; //calls the estimate cost function and passes carNum and dayNum as arguments
			break;
			case 5:
				sortMake.sortByMake(); //calls sortbymake function
				sortMake.print(); //calls print function after object has been sorted
			break;
			case 6:
				sortPrice.sortByPrice(); //calls sortbyprice function
				sortPrice.print(); //calls print function after object has been sorted
			break;
			case 7:
				userSearch = new char[20];
				cout << "Please enter the make you would like to search for: ";
				cin >> userSearch; //gets the make from the user
				inv.searchByMake(userSearch); //calls searchbymake function and passes userSearch as an argument
				delete[] userSearch;
				userSearch = NULL;
			break;
			case 8:
				cout << "Exiting program" << endl; //notifies the user of the program termination
			break;
			default:
				cout << "Invalid entry" << endl; //states invalid entry if user enters something other than the numbers 1-8
				userChoice = 0;
		}
	} while (userChoice != 8); //exits loop if user enters 8

	delete[]fileName;
	fileName = NULL;

	return 0;
}
