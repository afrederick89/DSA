/*
 * Client.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Alex
 */

#include "Client.h"

int main(int argc, char *argv[]){
	double SQside;
	double Tside[2];
	Square* mySquare;
	Triangle* myTriangle;
	cout << "Enter the length of the squares sides: ";
	cin >> SQside;
	mySquare = new Square(SQside);
	cout << "\nThe Area of your square is: ";
	printArea(mySquare);
	cout << "\nThe Perimeter of your square is: ";
	printPerimeter(mySquare);
	cout << "\n\nEnter the length of the triangles first side: ";
	cin >> Tside[0];
	cout << "Second Side: ";
	cin >> Tside[1];
	cout << "Third Side: ";
	cin >> Tside[2];
	myTriangle = new Triangle(Tside);
	cout << "\nThe Area of your triangle is: ";
	printArea(myTriangle);
	cout << "\nThe Perimeter of your triangle is: ";
	printPerimeter(myTriangle);
	cout << "\n\nSquare Perimeter: ";
	printPerimeter(mySquare);
	cout << "\nTriangle Perimeter: ";
	printPerimeter(myTriangle);
	cout << "\nSquare Area: ";
	printArea(mySquare);
	cout << "\nTriangle Area: ";
	printArea(myTriangle);

	cout << "\n\nPart 2\n";
	cout << "First and Last Name: ";
	for(int index = 1; index < argc; ++index)
		cout << argv[index] << " ";
	cout << "\nSecond Letters: ";
	for(int index =1; index < argc; ++index)
		cout << argv[index][1] << " ";
	return 0;

}


