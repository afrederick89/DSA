 /* Author:Alexander Frederick * Students Assignment *Due: 6 September 2017
  * CS1C Monday/Wednesday 1330 - 1620
  */


#include "cs1cStudent.h"


	cs1cStudent::cs1cStudent() : student(){
		score = 01;
		pythKnow = "NA";
	};
	cs1cStudent::cs1cStudent(string sName, int sID, string sPhNum,
			     int sAge, char sGender, string sStanding, float sGpa,
				 int sScore, string sPythKnow, int cMonth, int cDay,
				 int cYear) : student(sName, sID, sPhNum, sAge, sGender,
						              sStanding, sGpa){
		score = sScore;
		pythKnow = sPythKnow;
		gradDate.changeDate(cMonth, cDay, cYear);

	};
	cs1cStudent::~cs1cStudent(){

	};
	void cs1cStudent::ChangeScore(){
		cout << "\nStudent Score: " << score;
		cout << "\nChange score to: ";
		cin >> score;
	};
	void cs1cStudent::ChangeKnowl(){
		cout << "\nStudent Python Knowledge: " << pythKnow;
		cout << "\nChange Python Knowledge to: ";
		getline(cin, pythKnow);
	};
	void cs1cStudent::ChangeGradDate(){
		int m, d, y;
		cout << "\nStudent Graduation Date: " << gradDate;
		cout << "\nChange graduation date to: \nMonth:";
		cin >> m;
		cout << "Day: ";
		cin >> d;
		cout << "Year: ";
		cin >> y;
		gradDate.changeDate(m, d, y);
	};
	void cs1cStudent::PrintStudent() const{
		student::PrintStudent();
		cout << "\nAssignment Score: " << score;
		cout << "\nPython Knowledge: " << pythKnow;
		cout << "\nGraduation Date: " << gradDate << '\n';
	};
