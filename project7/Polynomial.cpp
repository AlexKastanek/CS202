#include <iostream>
#include <fstream>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial() { //default constructor

	maxDeg = 3;

	coefficients = new int[maxDeg + 1];

}

Polynomial::Polynomial(int a, int* b) { //parameterized constructor

	maxDeg = a;

	coefficients = new int[maxDeg + 1];

	for (int i = 0; i < maxDeg + 1; i++) {
		coefficients[i] = b[i];
	}

}

Polynomial::Polynomial(const Polynomial& poly) { //copy constructor

	maxDeg = poly.maxDeg;

	coefficients = new int[maxDeg + 1];

	for (int i = 0; i < maxDeg + 1; i++) {
		coefficients[i] = poly.coefficients[i];
	}

}

Polynomial::~Polynomial() { //destructor

	delete[] coefficients;
	coefficients = NULL;

}

int Polynomial::solve(int x) const { //solves a polynomial when x is a constant value

	int num, var, finVal = 0;

	var = x;

	int j = 0;
	for (int i = maxDeg; i >= 0; i--) { //loop that goes through each term in the polynomial
		x = var;
		num = coefficients[j];
		for (int k = 1; k < i; k++) { //loop that multiplies x to the number of the degree
			x = var * x;
		}
		if (i == 0) {
			x = 1;
		}
		//cout << x << endl;
		finVal = finVal + (x * num);
		//cout << finVal << endl;
		j++;
	}

	return finVal;

}

void Polynomial::operator=(const Polynomial& poly) { //makes calling object equal to the argument

	delete[] coefficients; //deallocates the array of coefficients that was originally in the polynomial
	coefficients = NULL;
	
	maxDeg = poly.maxDeg;
	
	coefficients = new int[maxDeg + 1];

	for (int i = 0; i < maxDeg + 1; i++) { //loop that sets all coefficients in calling object equal to coefficieints in argument
		coefficients[i] = poly.coefficients[i];
	}

}

bool Polynomial::operator==(const Polynomial& poly) const { //compares two polynomial objects and returns true if they are equal to each other

	if (maxDeg != poly.maxDeg) { //if the max degrees are not equal to each other, returns false
		return false;
	}

	for (int i = 0; i < maxDeg; i++) {
		if (coefficients[i] != poly.coefficients[i]) { //if any coefficients are not equal to each other, returns false
			return false; 
		}
	}

	return true;

}

bool Polynomial::operator!=(const Polynomial& poly) const { //compares two polynomial objects and returns true if they are not equal to each other

	if (maxDeg != poly.maxDeg) { //if the max degrees are not equal to each other, returns true
		return true; 
	}

	for (int i = 0; i < maxDeg; i++) { 
		if (coefficients[i] != poly.coefficients[i]) { //if any coefficients are not equal to each other, returns true
			return true;
		}
	}

	return false;

}

Polynomial Polynomial::operator*(const Polynomial& poly) const { //multiplies a polynomial by another polynomial and returns a polynomial

	Polynomial max, min;
	bool alreadyUsed = false;
	//int* usedExp, *usedCoeff;
	int* exp = new int[(maxDeg + 1) * (poly.maxDeg + 1)];
	int* coeff = new int[(maxDeg + 1) * (poly.maxDeg + 1)];

	if (maxDeg > poly.maxDeg) { //tests to see which polynomial is greater than the other and sets max to the greater polynomial and min to the lesser one
		max = *this;
		min = poly;
	} else {
		max = poly;
		min = *this;
	}

	int decMax1 = max.maxDeg, decMax2 = min.maxDeg;

	int k = 0;
	for (int i = 0; i < min.maxDeg + 1; i++) { //nested loop that multiplies each coefficient of one polynomial by each coefficient of the other
		decMax1 = max.maxDeg;
		for (int j = 0; j < max.maxDeg + 1; j++) {
			coeff[k] = min.coefficients[i] * max.coefficients[j];
			exp[k] = decMax2 + decMax1;
			decMax1--;
			k++;
		}
		decMax2--;
	}

	/*for (int i = 0; i < (maxDeg + 1) * (poly.maxDeg + 1); i++) { debugging
		cout << coeff[i] << "x^" << exp[i] << endl;
	}*/

	//this second half of the function adds the like terms together

	int maxExp = exp[0];
	int sum = 0;
	int* matches;
	int newExp = maxExp;
	int* newCoeff = new int[maxExp + 1];

	//my method was to increment the amount of like terms by one until the half way point was reached. Once that point was reached, I would decrement the amount of like terms until the end

	if ((maxExp % 2) == 1) {
		maxExp++;
	}

	int count = 0;
	for (int i = 0; i < maxExp / 2; i++) { //this loop increments the amount of like terms until it reached half of the largest degree
		if (i == 0) { //if loop is on the first term, then there are no like terms, so it sets the first term of the new coefficient array to the coefficient the loop is on
			newCoeff[count] = coeff[count];
			count++;
		} else { //otherwise it stores all like terms in the matches array
			//match = 0;
			matches = new int[i + 1];
			int k = 0;
			for (int j = 0; j < (maxDeg + 1) * (poly.maxDeg + 1); j++) {
				if (exp[j] == newExp - count) {
					matches[k] = coeff[j];
					k++;
				}
			}
			sum = 0;
			for (int j = 0; j < k; j++) { //after all like terms have been stored, it adds them
				sum = sum + matches[j];
			}
			newCoeff[count] = sum;
			count++;
			delete[] matches;
			matches = NULL;
		}
	}

	//count = maxExp / 2; error checking

	for (int i = maxExp / 2; i >= 0; i--) { //repeats the above steps but this time it starts from the half way point and decrements until the maximum exponent is reached
		if (i == 0) {
			newCoeff[count] = coeff[(maxDeg + 1) * (poly.maxDeg + 1) - 1];
			count++;
		} else {
			//match = 0;
			matches = new int[i + 1];
			int k = 0;
			//cout << count;
			for (int j = 0; j < (maxDeg + 1) * (poly.maxDeg + 1); j++) {
				if (exp[j] == newExp - count) {
					matches[k] = coeff[j];
					k++;
				}
			}
			sum = 0;
			for (int j = 0; j < k; j++) {
				sum = sum + matches[j];
			}
			newCoeff[count] = sum;
			count++;
			delete[] matches;
			matches = NULL;
		}
	}

	Polynomial factor(newExp, newCoeff); //creates a polynomial with the new parameters

	return factor;

	delete[] matches;
	matches = NULL;
	delete[] newCoeff;
	newCoeff = NULL;
	delete[] exp;
	exp = NULL;
	delete[] coeff;
	coeff = NULL;

}

Polynomial Polynomial::operator*(int x) const { //multiplies a polynomial by a constant and returns a polynomial

	if (x == 1) { //if multiplying by one, then this statement just returns the calling object
		return *this;
	} else {
		Polynomial factor;
		factor = *this;
		for (int i = 0; i < maxDeg + 1; i++) { //mulitiplies each coefficient by the constant
			factor.coefficients[i] = coefficients[i] * x;
		}
		return factor;
	}

}

//friend functions:

ostream& operator<<(ostream& os, const Polynomial& poly) { //friend function that ouptuts the data inside the polynomial object passed as an argument

	//os << poly.maxDeg;
	//bool zero;
	char sign;
	int num;

	int j = 0;
	for (int i = poly.maxDeg; i >= 0; i--) { //outputs each term with the proper sign, coefficient, exponent, and structure
		sign = '+';
		num = poly.coefficients[j];
		if (num < 0) {
			num = num * -1;
			sign = '-';
			if (i == poly.maxDeg) {
				cout << sign;
			}
		}
		if (i == poly.maxDeg) {
			if (num != 0) {
				if (num != 1) {
					os << num << "x^" << i << " ";
				} else os << "x^" << i << " ";
			} else os << "0 ";
		} else if (i == 1) {
			if (num != 0) {
				if (num != 1) {
					os << sign << " " << num << "x" << " ";
				} else os << sign << " " << "x" << " ";
			}
		} else if (i == 0) {
			if (num != 0) {
				os << sign << " " << num;
			}
		} else {
			if (num != 0) {
				if (num != 1) {
					os << sign << " " << num << "x^" << i << " ";
				} else os << sign << " " << "x^" << i << " ";
			}
		}
		j++;
	}

	//error checking
	/*for (int i = 0; i < poly.maxDeg; i++) {
		zero = true;
		if (poly.coefficients[i] != 0) {
			zero = false;
			return os;
		}
	}

	if (zero) {
		os << 0;
		return os;
	}*/

	return os;

}

istream& operator>>(istream& is, Polynomial& poly) { //friend function that gets input and stores the data in the polynomial object passed as an argument

	is >> poly.maxDeg;

	delete[] poly.coefficients;
	poly.coefficients = NULL;
	poly.coefficients = new int[poly.maxDeg + 1];
	
	for (int i = 0; i < poly.maxDeg + 1; i++) {
		is >> poly.coefficients[i];
	}

	return is;

}

Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2) { //friend function that adds two polynomials together and returns a polynomial

	int lessDeg, maxDeg, degDif;
	Polynomial sum;

	if (poly1.maxDeg > poly2.maxDeg) { //statement that checks which polynomial is greater than the other
		sum = poly1;
		maxDeg = poly1.maxDeg;
		lessDeg = poly2.maxDeg;
		degDif = maxDeg - lessDeg;
		for (int i = 0; i < maxDeg + 1; i++) { //adds each like term
			if (i < degDif) {
				sum.coefficients[i] = poly1.coefficients[i];
			} else {
				sum.coefficients[i] = poly1.coefficients[i] + poly2.coefficients[i - degDif];
			}
		}
	} else {
		sum = poly2;
		maxDeg = poly2.maxDeg;
		lessDeg = poly1.maxDeg;
		degDif = maxDeg - lessDeg;
		for (int i = 0; i < maxDeg + 1; i++) { //adds each like term
			if (i < degDif) {
				sum.coefficients[i] = poly2.coefficients[i];
			} else {
				sum.coefficients[i] = poly1.coefficients[i - degDif] + poly2.coefficients[i];
			}
		}
	}

	return sum;

}

Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2) { //friend function that subtracts a polynomial from another and returns a polynomial

	//does the same thing as the + function but '+' signs are replaced with '-' signs

	int lessDeg, maxDeg, degDif;
	Polynomial dif;

	if (poly1.maxDeg > poly2.maxDeg) {
		dif = poly1;
		maxDeg = poly1.maxDeg;
		lessDeg = poly2.maxDeg;
		degDif = maxDeg - lessDeg;
		for (int i = 0; i < maxDeg + 1; i++) {
			if (i < degDif) {
				dif.coefficients[i] = poly1.coefficients[i];
			} else {
				dif.coefficients[i] = poly1.coefficients[i] - poly2.coefficients[i - degDif];
			}
		}
	} else {
		dif = poly2;
		maxDeg = poly2.maxDeg;
		lessDeg = poly1.maxDeg;
		degDif = maxDeg - lessDeg;
		for (int i = 0; i < maxDeg + 1; i++) {
			if (i < degDif) {
				dif.coefficients[i] = poly2.coefficients[i];
			} else {
				dif.coefficients[i] = poly1.coefficients[i - degDif] - poly2.coefficients[i];
			}
		}
	}

	return dif;

}
