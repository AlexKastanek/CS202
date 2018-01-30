#include <iostream>
#include <fstream>
#include "inheritance.h"

using namespace std;

int main() {

	ifstream fin;

	fin.open("data"); //getting data from file: "data"

	int shapeTotal;

	fin >> shapeTotal;

	Shape **list = new Shape*[shapeTotal]; //allocates list of shapes of size shapeTotal

	Shape (*(*cursor)) = list; //cursor to navigate the list

	for (int i = 0; i < shapeTotal; i++) { //loop that gets all of the data for each shape from the file, type of shape is dependant on the shapeID, then allocates memory for that specific type of shape
		int shapeID;
		fin >> shapeID;
		if (shapeID == 1) {
			float l, w;
			fin >> l;
			fin >> w;
			*cursor = new Rectangle(l, w);
		} else if (shapeID == 2) {
			float l, w, h;
			fin >> l;
			fin >> w;
			fin >> h;
			*cursor = new RectangularPrism(l, w, h);
		} else if (shapeID == 3) {
			float r;
			fin >> r;
			*cursor = new Circle(r);
		} else if (shapeID == 4) {
			float r, h;
			fin >> r;
			fin >> h;
			*cursor = new Cylinder(r, h);
		} else cout << "Error: Invalid entry" << endl;
		cursor++;
	}

	cursor = list;

	fin.close();

	for (int i = 0; i < shapeTotal; i++) { //loop that gets the perimeter or surface area of the shape that cursor is pointing to
		float val;
		val = (*(*cursor)).calculatePerimeterOrSurfaceArea();
		if ((*(*cursor)).is3D()) {
			cout << "The surface area of a ";
			(*(*cursor)).print();
			cout << " is: " << val << endl;
		} else {
			cout << "The perimeter of a ";
			(*(*cursor)).print();
			cout << " is: " << val << endl;
		}
		cursor++;
	}

	cursor = list;

	cout << endl;

	for (int i = 0; i < shapeTotal; i++) { //loop that gets the area or volume of the shape that cursor is pointing to
		float val;
		val = (*(*cursor)).calculateAreaOrVolume();
		if ((*(*cursor)).is3D()) {
			cout << "The volume of a ";
			(*(*cursor)).print();
			cout << " is: " << val << endl;
		} else {
			cout << "The area ";
			(*(*cursor)).print();
			cout << " is: " << val << endl;
		}
		cursor++;
	}

	cursor = list;

	delete[] list;
	list = NULL;

	cursor = NULL;

	return 0;

}
