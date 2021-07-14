/*
 * Client.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Alex
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include <iostream>
#include <math.h>

using namespace std;

class Shape {
public:
	Shape() {};
	~Shape() {};
	virtual double calcPerimeter() = 0;
	virtual double calcArea() = 0;
};

class Square : public Shape {
public:
	Square() {};
	Square(double s) {
		sides = s;
	}
	~Square() {};
	double calcPerimeter(){
		return (sides*4);
	};
	double calcArea(){
		return (sides*sides);
	};
private:
	double sides;
};

class Triangle : public Shape {
public:
	Triangle(){};
	Triangle(double s[]) {
		for(int i=0;i<3;++i) {
			side[i] = s[i];
		}

	};
	~Triangle() {};
	double calcPerimeter(){
		double p;
		for(int i = 0; i<3;++i){
			p += side[i];
		}
		return p;
	};
	double calcArea() {
		double a, s;
		s = (side[0] +side[1] + side[2]) / 2;
		a = sqrt(s*(s-side[0])*(s-side[1])*(s-side[2]));
		return a;
	};
private:
	double side[2];

};

void printPerimeter(Shape* pShape) {
	cout << pShape->calcPerimeter();

};

void printArea(Shape* aShape) {
	cout << aShape->calcArea();
};


#endif /* CLIENT_H_ */
