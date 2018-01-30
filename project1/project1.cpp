/***************************************************************/
/* 
	Alex Kastanek
	CS202
	Project 1
	This project asks user for the name of a file that contains
	10 names in no particular order. It then sorts the names
	alphabetically and prints them along with the original list
	to screen as well as writes the sorted list to a separate
	file
*/
/***************************************************************/

#include <iostream> 
#include <fstream>

using namespace std;

char sort_names(char names[10][20]); //a function that sorts the names alphabetically

int main() {

	//int flag = 0; //a variable I initialized but never used
	char names[10][20]; //declaring an array to store each name
	char fileInputName[20], fileOutputName[20]; //declaring arrays to store the name of the input and output files

	//cout << "Please enter the names of 3 individuals:" << endl; //testing
	cout << "Please enter the name of the file you would like to sort: ";
	cin >> fileInputName;
	cout << "Please enter a name for the file that the sorted names will be written to: ";
	cin >> fileOutputName;

	ifstream fin; //declaring file variable as well as opening a writable file
	fin.open(fileInputName);

	for (int i = 0; i < 10; i++) { //assigning the file data to names
		fin >> names[i];
	}
	
	cout << "-----------------------------------------------------" << endl;
	cout << "The original list of names you entered is as follows:" << endl; //printing to screen the original list of names without sorting
	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << names[i] << endl;
		//cout << namesAlph[i] << endl;
	}
	cout << "-----------------------------------------------------" << endl;
	
	//*******************************************************************
	//below is my first attempt at sorting the names alphabetically
	//I'm leaving it in to show my process of work
	//*******************************************************************

	/*for (int i = 0; i < 6; i++)  {
		for (int j = 0; j < 3; j++) {
			if (j == 2) {
				if (names[j][0] < names[0][0]) {
					for (int k = 0; k < 20; k++) {
						namesAlph[j][k] = names[j][k];
					}
				} else {
					for (int k = 0; k < 20; k++) {
						namesAlph[j][k] = names[0][k];
					}
				}
			} else if (names[j][0] < names[j + 1][0]) {
				for (int k = 0; k < 20; k++) {
					namesAlph[j][k] = names[j][k];
				}
			} else {
				for (int k = 0; k < 20; k++) {
					namesAlph[j][k] = names[j + 1][k];
				}
			}
		}
		//cout << namesAlph[i] << endl;
		if (namesAlph[0][0] < namesAlph[1][0] && namesAlph[1][0] < namesAlph[2][0]) {
			flag = 1;
		}
	}*/

	sort_names(names); //calling the sort_names function

	fin.close(); //closing the file
	
	//writing to the output file
	ofstream fout;
	fout.open(fileOutputName);
	for (int i = 0; i < 10; i++) {
		fout << names[i] << endl;
	}

	cout << "The sorted list of names you entered is as follows:" << endl; //printing to screen the sorted listed of names
	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << names[i] << endl;
		//cout << namesAlph[i] << endl;
	}
	cout << "-----------------------------------------------------" << endl;

	cout << "Your sorted list has been written to the file \"" << fileOutputName << ".\"" << endl;
	cout << "-----------------------------------------------------" << endl;

return 0;
}

char sort_names(char names[10][20]) { 

	char temp[20]; //declaring a temp variable to hold the arrays as the function swaps them

	for (int i = 0; i < 9; i++) { //goes through the list of names from top to bottom
		while (names[i][0] > names[i + 1][0]) { //swaps the names if they are out of order
			for (int j = 0; j < 20; j++) { //this set of for loops that switch the names letter by letter
				temp[j] = names[i + 1][j];
			}
			for (int j = 0; j < 20; j++) {
				names[i + 1][j] = names[i][j];
			}
			for (int j = 0; j < 20; j++) {
				names[i][j] = temp[j];
			}
			i--; //a reset that moves the loop back, it basically acts as an error checker
			if (names[i][0] == names[i + 1][0]) { //checks to see if first letters of compared names are the same
				//cout << "test00 - " << names[i] << endl; //debugging
				int k = 0;
				while (names[i][k] == names[i + 1][k]) { //loop that runs until the first letters of compared names aren't the same anymore
					//cout << "test01 - " << names[i][k] << endl; //debugging
					while (names[i][k + 1] > names[i + 1][k + 1]) { //swaps the names if they are out of order in reference to the 'k' letter
						//cout << "test02" << endl; //debugging
						for (int j = 0; j < 20; j++) { //another set of for loops that switch the names letter by letter
							temp[j] = names[i + 1][j];
						}
						for (int j = 0; j < 20; j++) {
							names[i + 1][j] = names[i][j];
						}
						for (int j = 0; j < 20; j++) {
							names[i][j] = temp[j];
						}
						i--; //another reset that moves the loop back
					}
					k++; //increments k to check letters until they aren't the same anymore
				}
			}
		}
	}

	for (int i = 9; i > 1; i--) { //goes through the list of names from bottom to top
		while (names[i][0] < names[i - 1][0]) { //swaps the names if they are out of order
			for (int j = 0; j < 20; j++) { //another set of for loops that switch the names letter by letter
				temp[j] = names[i][j];
			}
			for (int j = 0; j < 20; j++) {
				names[i][j] = names[i - 1][j];
			}
			for (int j = 0; j < 20; j++) {
				names[i - 1][j] = temp[j];
			}
			i++; //another reset that moves the loop back
		}
	}

}