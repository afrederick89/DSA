// /*Author: Alexander Frederick * Software Tester Assignment * Due:2 October 2017
//  *CS1C Monday/Wednesday 1330 - 1620
//  */
//
//#include "client.h"
//
//int main () {
//	const int SWT_MAX = 4;
//	int choice = 0;
//	int stuChoice = 0;
//	SoftwareTester *currentSwTesters[SWT_MAX];
//	currentSwTesters[0] = new SoftwareTester("Joe Calculus", 64879, "945-555-1234", 22,
//											 'M', "Freshman", 3.3, "1234 Main Avenue",
//											 "Laguna Niguel", "CA", 92677);
//	currentSwTesters[1] = new SoftwareTester("Mary Algebra", 76309, "312-555-5555", 19,
//												 'F', "Sophomore", 3.26, "3333 Marguerite Pkwy",
//												 "Mission Viejo", "CA", 92646);
//	currentSwTesters[2] = new SoftwareTester("Jo Trig", 10192, "713-703-1234", 24,
//													 'F', "Sophomore", 3.29, "9876 Elm Street",
//													 "San Clemente", "CA", 92672);
//	cout << "\nDeep Copying Jo Trig\n";
//	currentSwTesters[3] = new SoftwareTester(*currentSwTesters[2]);
//	cout << "Testing Pass by copy, return by copy";
//	currentSwTesters[3]->ValueTest(*currentSwTesters[2]);
//
//	while(stuChoice < 10) {
//		cout << "Which student would you like to view?\n";
//		for(int i=0;i<4;++i){
//			cout << "(" << i << ")";
//			currentSwTesters[i]->PrintName();
//		}
//		cin >> stuChoice;
//		cin.ignore(1000, '\n');
//		while(choice < 6) {
//			cout << "What would you like to change?\n";
//			cout << "(1)Address\n(2)City\n(3)State\n(4)ZipCode\n(5)Print Student\n";
//			cin >> choice;
//			cin.ignore(1000, '\n');
//			if(choice < 6){
//				switch(choice) {
//				case 1: currentSwTesters[stuChoice]->ChangeAddress();
//					break;
//				case 2: currentSwTesters[stuChoice]->ChangeCity();
//					break;
//				case 3: currentSwTesters[stuChoice]->ChangeState();
//					break;
//				case 4: currentSwTesters[stuChoice]->ChangeZip();
//					break;
//				case 5: currentSwTesters[stuChoice]->PrintStudent();
//					break;
//				default : cout << "\nError\n";
//					break;
//				}
//			}
//		}
//		choice = -1;
//		stuChoice = -1;
//	}
//	return 0;
//
//}
//
//
