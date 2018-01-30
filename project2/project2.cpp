#include <iostream>
#include <fstream>
using namespace std;

struct rentalCar {
	char make[11];
	char model[21];
	int year;
	float price;
	bool availability;
};

void get_input(rentalCar*, char*); //function that reads information from a file and stores it in an array of structs

void print_data(rentalCar*); //prints all of the data in the array of size 10 of the struct rentalCar

void estimate_cost(rentalCar*, int&, int&); //estimates the cost of renting a particular car over a certain span of days

void most_expensive(rentalCar*); //finds the most espensive car in a list of cars

void print_available(rentalCar*); //prints the available cars from a list of cars

int main() {

	rentalCar carStats[10]; //initializing my variables
	char fileName[21];
	int userChoice;

	cout << "Please enter the name of the file: "; //getting the name of the file from the user
	cin >> fileName;
	get_input(carStats, fileName); //calls get_input function to read in data from a file

	do { //a loop that keeps the menu running while the user does not enter 5 as a choice
		cout << "===========================================" << endl; //menu display
		cout << "Please choose one of the following options:" << endl; //prompting the user for a choice
		cout << "1) Print out all data for all of the cars" << endl;
		cout << "2) Estimate car rental cost" << endl;
		cout << "3) Find the most expensive car" << endl;
		cout << "4) Print out only the available cars" << endl;
		cout << "5) Exit program" << endl;

		userChoice = 0; //defaulting user's choice at 0
		cin >> userChoice; 

		switch (userChoice) {
			case 1: //calls print_data function if user enters 1
				cout << endl << "================================" << endl;
				cout << "All data for every car:" << endl;
				cout << "================================" << endl;
				print_data(carStats);
				break;
			case 2: //calls estimate_cost function if user enters 2
				int dayNum, carNum;
				cout << endl << "================================" << endl;
				cout << "Estimation of car rental price:" << endl;
				cout << "================================" << endl;
				estimate_cost(carStats, dayNum, carNum);
				cout << " over a " << dayNum << " day span." << endl; //I put this out of the function to prove that the pass by reference works
				cout << "------------------------------------------------" << endl;
				break;
			case 3: //calls most_expensive function if user enters 3
				cout << endl << "================================" << endl;
				cout << "The most expensive car:" << endl;
				cout << "================================" << endl;
				most_expensive(carStats);
				break;
			case 4: //calls print_available function if user enters 4
				cout << endl << "==========================" << endl;
				cout << "Car availability:" << endl;
				cout << "==========================" << endl;
				print_available(carStats);
				break;
			case 5: //if user enters 5, sets user choice to 5 so the program will end at the end of loop
				userChoice = 5;
				break;
			default:
				cout << "invalid choice" << endl;
				userChoice = 0; //defaulting user's choice at 0 again, so if an invalid character is entered, userChoice = 0 instead of that invalid choice
		}
	} while (userChoice != 5);

return 0;
}

void get_input(rentalCar carStats[10], char fileName[21]) {
	ifstream fin;
	fin.open(fileName);
	for (int i = 0; i < 10; i++) { //loop that gets all the data from a user defined file and stores it into an array of structs (rentalCar)
		fin >> carStats[i].year;
		fin >> carStats[i].make;
		fin >> carStats[i].model;
		fin >> carStats[i].price;
		fin >> carStats[i].availability;
	}
	fin.close();
}

void print_data(rentalCar carStats[10]) {
	cout << "--------------------------------" << endl;
	for (int i = 0; i < 10; i++) { //loop that goes through all the data of the array of structs and prints it to screen
		//cout << endl;
		cout << "Car " << i + 1 << " is a ";
		cout << carStats[i].year << " ";
		cout << carStats[i].make << " ";
		cout << carStats[i].model << "." << endl;
		cout << "It costs $" << carStats[i].price << " dollars per day." << endl;
		if (carStats[i].availability == true) {
			cout << "It is currently available!" << endl;
		} else cout << "It is currently unavailable." << endl;
		cout << "--------------------------------" << endl;
	}
}

void estimate_cost(rentalCar carStats[10], int &numberOfDays, int &carNumber) {
	float estimation;
	cout << "Please enter the car number of your choice (1 - 10): ";
	cin >> carNumber;
	cout << "Please enter the amount of days you would like to rent this car: ";
	cin >> numberOfDays;
	estimation = carStats[carNumber - 1].price * (float) numberOfDays; //calculates how much the car will cost when rented for a user define number of days
	cout << "------------------------------------------------" << endl;
	cout << "Your " << carStats[carNumber].year << " " << carStats[carNumber].make << " " << carStats[carNumber].model << " will cost approximately " << endl; 
	cout << "$" << estimation << " dollars";
}

void most_expensive(rentalCar carStats[10]) {	
	int expCar;
	for (int i = 0; i < 10; i++) { //a loop that determines the most expensive car
		if (i == 0) {
			expCar = i;
		} else {
			if (carStats[expCar].price < carStats[i].price) {
				expCar = i;
			}
		}
	}
	cout << "--------------------------------" << endl;
	cout << "The most expensive car is the " << endl << carStats[expCar].year << " " << carStats[expCar].make << " " << carStats[expCar].model << " starting at " << endl << carStats[expCar].price << " per day." << endl;
	cout << "--------------------------------" << endl;
}

void print_available(rentalCar carStats[10]) {
	for (int i = 0; i < 10; i++) {
		if (carStats[i].availability == true) { //prints if the car is available if the availability is true or 1
			cout << "--------------------------" << endl;
			cout << "The " << carStats[i].year << " " << carStats[i].make << " " << carStats[i].model << endl << "is available for rent." << endl;
			cout << "--------------------------" << endl;
		}
	}
}
