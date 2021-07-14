 /*Author: Alexander Frederick * Students Assignment * Due:9 October 2017
  *CS1C Monday/Wednesday 1330 - 1620
  */

#include "SWTester.h"

int main () {
	student stu1;
	int choice = 1;
	while(choice != 0){
	cout << "Enter the First Student: \n";
	cin >> stu1;
	cout << "\nEnter 0 to Exit.\n";
	cin >> choice;
	}
	cout << stu1;
	return 0;

}
