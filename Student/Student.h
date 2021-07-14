 /*  Author: Alexander Frederick * Students Assignment * Due: 6 September 2017
  *  CS1C Monday/Wednesday 1330 - 1620
  */
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class student {
public :
	student();
	student(string, int, string, int, char, string, float);
	~student();
	void ChangeName();
	void ChangeID();
	void ChangePhoneNum();
	void ChangeAge();
	void ChangeStanding();
	void ChangeGPA();
	void PrintStudent() const;
	void PrintName() const;
	int AddAge(int);
	student operator+(int);
	bool operator==(const student&);
	friend istream& operator>>(istream& in, student& inStu);
	friend ostream& operator<<(ostream& out, student& outStu);
	friend bool CompAge(student&, student&);

private :
	string name;
	int ID;
	string phoneNum;
	int age;
	char gender;
	string classStanding;
	float GPA;
};




#endif /* STUDENT_H_ */
