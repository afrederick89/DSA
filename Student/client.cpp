// /*Author: Alexander Frederick * Students Assignment * Due:6 September 2017
//  *CS1C Monday/Wednesday 1330 - 1620
//  */
//
//#include "client.h"
//
//int main () {
//	const int CS_STU_MAX = 3; //Number of CS students
//	const int STU_MAX = 4; //Number of non-cs students
//	const int SWT_MAX = 3;
//
//	int userChoice; //IN - Users first menu choice
//	int stuChoice; //IN - Users student profile choice
//
//	student currentStudents[STU_MAX];
//	currentStudents[0] = student("Celine Dion", 44444, "949-555-1234",
//								 49, 'F', "Freshman", 4.0);
//	currentStudents[1] = student("Madonna", 123456, "714-555-5555",
//			                     59, 'F', "Sophomore", 3.23);
//	currentStudents[2] = student("Jennifer Lopez", 876542, "760-703-1234",
//			                     48, 'F', "Sophomore", 3.79);
//	currentStudents[3] = student("Lady Gaga", 777744, "213-555-6789",
//			                     31, 'F', "Freshman", 2.10);
//
//	cs1cStudent currentCS1CStu[CS_STU_MAX];
//	currentCS1CStu[0] = cs1cStudent ("Adele", 667788, "949-665-1234",
//			                         29, 'F', "Freshman", 3.3, 500, "No",
//									 5, 12, 2017);
//	currentCS1CStu[1] = cs1cStudent ("Taylor Swift", 156789, "248-555-6543",
//			                         27, 'M', "Sophomore", 3.9, 700, "No",
//									 5, 11, 2018);
//	currentCS1CStu[2] = cs1cStudent ("Bruno Mars", 876543, "703-703-7654",
//			                         31, 'F', "Sophomore", 3.2, 800, "Yes",
//									 5, 11, 2017);
//
//	SoftwareTester currentSwTesters[SWT_MAX];
//	currentSwTesters[0] = SoftwareTester("Joe Calculus", 64879, "945-555-1234", 22,
//										 'M', "Freshman", 3.3, "1234 Main Avenue",
//										 "Laguna Niguel", "CA", 92677);
//
//
//	cout << "Welcome to the student directory!\n";
//	while(userChoice != 11) {
//		cout << "\nWhat would you like to do?\n";
//		cout << "(1) View Student\n(2) Change Student Name\n";
//		cout << "(3) Change Student ID Number\n(4) Change Student "
//				"Phone Number\n";
//		cout << "(5) Change Student Age\n(6) Change Student "
//				"Class Standing\n";
//		cout << "(7) Change Student GPA\n(8) Change Student Score\n"
//				"(9) Change Student Python Knowledge\n("
//				"10) Change Student Graduation Date\n"
//				"(11) Exit Application\n";
//		cin >> userChoice;
//		if(cin.fail() || userChoice > 11 || userChoice < 1) {
//			cin.clear();
//			cin.ignore(10000, '\n');
//			cout << "\nInvalid entry, please enter an integer from 1-11\n";
//		} else {
//			if(userChoice != 11){
//				stuChoice = studentChoice(currentStudents, currentCS1CStu,
//						                 STU_MAX, CS_STU_MAX);
//				if(stuChoice < STU_MAX){
//					switch(userChoice) {
//						case 1: currentStudents[stuChoice].PrintStudent();
//							break;
//						case 2: currentStudents[stuChoice].ChangeName();
//							break;
//						case 3: currentStudents[stuChoice].ChangeID();
//							break;
//						case 4: currentStudents[stuChoice].ChangePhoneNum();
//							break;
//						case 5: currentStudents[stuChoice].ChangeAge();
//							break;
//						case 6: currentStudents[stuChoice].ChangeStanding();
//							break;
//						case 7: currentStudents[stuChoice].ChangeGPA();
//							break;
//						default: cout << "\nCategory does not exist for this "
//								         "student\n";
//							break;
//						}
//				} else {
//					stuChoice -= STU_MAX;
//					switch(userChoice) {
//						case 1: currentCS1CStu[stuChoice].PrintStudent();
//							break;
//						case 2: currentCS1CStu[stuChoice].ChangeName();
//							break;
//						case 3: currentCS1CStu[stuChoice].ChangeID();
//							break;
//						case 4: currentCS1CStu[stuChoice].ChangePhoneNum();
//							break;
//						case 5: currentCS1CStu[stuChoice].ChangeAge();
//							break;
//						case 6: currentCS1CStu[stuChoice].ChangeStanding();
//							break;
//						case 7: currentCS1CStu[stuChoice].ChangeGPA();
//							break;
//						case 8: currentCS1CStu[stuChoice].ChangeScore();
//							break;
//						case 9: currentCS1CStu[stuChoice].ChangeKnowl();
//							break;
//						case 10: currentCS1CStu[stuChoice].ChangeGradDate();
//							break;
//						default: cout << "\nInvalid Entry\n";
//							break;
//					}//End Switch for cs1c
//				}//End If/Else if(stuChoice < STU_MAX)
//			} //End if(userChoice != 11)
//		}//End If/Else if(cin.fail() || userChoice > 11 || userChoice < 1)
//	}//End while(userChoice != 11)
//  return 0;
//}
//
