#include <iostream>
#include <fstream>

using namespace std;

class Polynomial {

public:
	
	Polynomial();
	Polynomial(int, int*);
	Polynomial(const Polynomial&);
	~Polynomial();

	int solve(int) const;
	void operator=(const Polynomial&);
	bool operator==(const Polynomial&) const;
	bool operator!=(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
	Polynomial operator*(int) const;

	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, const Polynomial&);
	friend ostream& operator<<(ostream& os, const Polynomial&);
	friend istream& operator>>(istream& is, Polynomial&);

private:

	int* coefficients;
	int maxDeg;

};
