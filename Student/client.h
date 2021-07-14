 /*  Author: Alexander Frederick * Students Assignment * Due: 6 September 2017
  *  CS1C Monday/Wednesday 1330 - 1620
  */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "student.h"
#include "date.h"
#include "cs1cStudent.h"
#include "SWTester.h"

int studentChoice(student stuAR[], cs1cStudent currentCS1CStu[], int regstu, int CSstu){
	int choice;
	int count = 0;
	cout << "Which student would you like to view?\n";
	for(int i = 0; i < regstu; ++i) {
		cout << "(" << count+1 << ")";
		stuAR[i].PrintName();
		++count;
	}
	for(int i = 0; i < CSstu; ++i) {
		cout << "(" << count+1 << ")";
		currentCS1CStu[i].PrintName();
		++count;
	}
	cin >> choice;
	cin.ignore(10000, '\n');
	return choice-1;
};

#endif /* CLIENT_H_ */
