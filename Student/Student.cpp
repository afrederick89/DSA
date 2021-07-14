 /*Author: Alexander Frederick * Students Assignment * Due:9 October 2017
  *CS1C Monday/Wednesday 1330 - 1620
  */

#include "Student.h"

student::student() {
	name = "New Student";
	ID = 123;
	phoneNum = "123-4568";
	age = 999;
	gender = 'N';
	classStanding = "NA";
	GPA = 99.99;
};
student::student(string sName, int sID, string sPhNum, int sAge,
		         char sGender, string sStanding, float sGpa){
	name = sName;
	ID = sID;
	phoneNum = sPhNum;
	age = sAge;
	gender = sGender;
	classStanding = sStanding;
	GPA = sGpa;
}
student::~student(){

};
void student::ChangeName(){
	cout << "\nStudent Name: " << name;
	cout << "\nNew Name: ";
	getline(cin, name);
};
void student::ChangeID(){
	cout << "\nStudent ID: " << ID;
	cout << "\nChange ID to: ";
	cin >> ID;
	cin.ignore(10000, '\n');
};
void student::ChangePhoneNum(){
	cout << "\nPhone Number: " << phoneNum;
	cout << "\nNew Phone Number: ";
	getline(cin, phoneNum);
};
void student::ChangeAge(){
	cout << '\n' << name <<  "'s Age: " << age;
	cout << "\nChange age to: ";
	cin >> age;
	cin.ignore(10000, '\n');
};
void student::ChangeStanding(){
	cout << "\nCurrent Standing: " << classStanding;
	cout << "\nChange grade to: ";
	getline(cin, classStanding);
};
void student::ChangeGPA(){
	cout << "\nCurrent GPA: " << GPA;
	cout << "\nChange GPA to: ";
	cin >> GPA;
	cin.ignore(10000, '\n');
};
void student::PrintStudent() const{
	cout << "\nStudent Name: " << name;
	cout << "\nStudent ID: " << ID;
	cout << "\nStudent Age: " << age;
	cout << "\nStudent Phone Number: " << phoneNum;
	cout << "\nStudent Standing: " << classStanding;
	cout << "\nStudent GPA: " << GPA << '\n';
};
void student::PrintName() const {
	cout << name;
};
int student::AddAge(int in){
	cout << "\nYou added " << in << " years.\n";
	age += in;
	return age;
}

student student::operator+(int inAge){
	student temp = *this;
	cout << "\nYou added " << inAge << " years.\n";
	temp.age += inAge;
	return temp;
}
bool student::operator==(const student& rStu){
	student temp = rStu;
	student Ttemp = *this;
	return CompAge(Ttemp, temp);
}
istream& operator>>(istream& in, student& inStu){
	try
	{
		cout << "Enter Name: ";
		in >> inStu.name;
		cout << "Enter ID: ";
		in >> inStu.ID;
		cout << "Enter Age: ";
		in >> inStu.age;
		assert(inStu.age > 0);
		if(inStu.age < 9)
			throw inStu.age;
		cout << "Enter Phone Number: ";
		in >> inStu.phoneNum;
		cout << "Enter Class Standing: ";
		in >> inStu.classStanding;
		cout << "Enter GPA: ";
		in >> inStu.GPA;
		if(inStu.GPA < 0)
			throw inStu.GPA;
	}
	catch(int e){
		cout << e << " is too young for college.\n"
			 << "Setting Age to 18.\n";
		inStu.age = 18;
	}
	catch(float e) {
		cout << e << " is too low for a GPA.\n"
			 << "Setting GPA to 2.0.\n";
		inStu.GPA = 2.0;
	}

	return in;
}
ostream& operator<<(ostream& out, student& outStu){
	out << "\nStudent Name: " << outStu.name
		<< "\nStudent ID: " << outStu.ID
	    << "\nStudent Age: " << outStu.age
	    << "\nStudent Phone Number: " << outStu.phoneNum
	    << "\nStudent Standing: " << outStu.classStanding
	    << "\nStudent GPA: " << outStu.GPA << '\n';
	return out;
}
bool CompAge(student& lStu, student& rStu){
	bool isEqual;
	if(lStu.age == rStu.age){
		isEqual = true;
	} else {
		isEqual = false;
	}
	return isEqual;
}
