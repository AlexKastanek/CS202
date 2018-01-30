#include <iostream>
#include <fstream>
#include <cmath>
#include "inheritance.h"

using namespace std;

Rectangle::Rectangle(float a, float b) { //Rectangle constructor

	length = a;

	width = b;

	isThreeDimensional = false;

	//cout << "Rectangle created" << endl; testing inheritance order

}

float Rectangle::calculateAreaOrVolume() { //returns the equation for calculating a rectangle's area

	return (length * width);

}

float Rectangle::calculatePerimeterOrSurfaceArea() { //returns the equation for calculating a rectangle's perimeter

	return (2 * (length + width));

}

void Rectangle::print() { //prints the data of the rectangle (length and width)

	cout << "rectangle with length: " << length << " and width: " << width;

	return;

}

RectangularPrism::RectangularPrism(float a, float b, float c) { //Rectangular Prism constructor

	length = a;

	width = b;

	height = c;

	isThreeDimensional = true;

	//cout << "Rectangular Prism created" << endl; testing inheritance order

}

float RectangularPrism::calculateAreaOrVolume() { //returns the equation for calculating a rectanglular prism's volume

	return (length * width * height);

}

float RectangularPrism::calculatePerimeterOrSurfaceArea() { //returns the equation for calculating a rectanglular prism's surface area

	return (2 * ((length * width) + (length * height) + (width * height)));

}

void RectangularPrism::print() { //prints the data of a rectangular prism (length, width, and height

	cout << "rectanglular prism with length: " << length << ", width: " << width << ", and height: " << height;

	return;

}

Circle::Circle(float a) { //Circle constructor

	radius = a;

	isThreeDimensional = false;

	//cout << "Circle created" << endl; testing inheritance order

}

float Circle::calculateAreaOrVolume() {

	return (M_PI * (radius * radius)); //returns the equation for calculating the area of a circle

}

float Circle::calculatePerimeterOrSurfaceArea() { //returns the equation for calculating the perimeter (circumference) of a circle

	return (2 * M_PI * radius);

}

void Circle::print() { //prints the data of a circle (the radius)

	cout << "circle with radius: " << radius;

	return;

}

Cylinder::Cylinder(float a, float b) { //Cylinder constructor

	radius = a;

	height = b;

	isThreeDimensional = true;

	//cout << "Cylinder created" << endl; testing inheritance order

}

float Cylinder::calculateAreaOrVolume() { //returns equation for calculating the volume of a cylinder

	return (M_PI * (radius * radius) * height);

}

float Cylinder::calculatePerimeterOrSurfaceArea() { //returns equation for calculating the surface area of a cylinder

	return ((2 * M_PI * radius * height) + (2 * M_PI * (radius * radius)));

}

void Cylinder::print() { //prints the data in a Cylinder (radius and height)

	cout << "cylinder with radius: " << radius << " and height: " << height;

	return;

}





