 /*Author: Alexander Frederick * Students Assignment * Due:9 October 2017
  *CS1C Monday/Wednesday 1330 - 1620
  */
#include "SWTester.h"
using namespace std;

SoftwareTester::SoftwareTester(){
	address = NULL;
	city = NULL;
	state = NULL;
	zipcode = 0;
}
SoftwareTester::SoftwareTester(const SoftwareTester &cSwTester) : student(cSwTester){
	this->address = cSwTester.address;
	this->city = cSwTester.city;
	this->state = cSwTester.state;
	this->zipcode = cSwTester.zipcode;
}

SoftwareTester::SoftwareTester(string sName, int sID, string sPhNum, int sAge, char sGender,
							   string sStanding, float sGpa, char* sAddress, char* sCity, char* sState, int sZip) :
		student(sName,sID,sPhNum,sAge, sGender, sStanding,sGpa){

	address = sAddress;
	city = sCity;
	state = sState;
	zipcode = sZip;
}

SoftwareTester::~SoftwareTester(){
	delete address;
	delete city;
	delete state;
}
void SoftwareTester::ChangeAddress(){
	cout << "\nCurrent address is: " << address;
	cout << "\nEnter the new Address: ";
	delete address;
	address = new char [100];
	cin.getline(address ,100);
}
void SoftwareTester::ChangeCity() {
	cout << "\nCurrent city is: " << city;
	cout << "\nEnter new city: ";
	delete city;
	city = new char [100];
	cin.getline(city,100);
}
void SoftwareTester::ChangeState(){
	cout << "\nCurrent state is: " << state;
	cout << "\nEnter new state: ";
	delete state;
	state = new char [100];
	cin.getline(state,100);

}
void SoftwareTester::ChangeZip(){
	cout << "\nCurrent zipcode is: " << zipcode;
	cout << "\nEnter new zipcode: ";
	cin >> zipcode;
	cin.ignore(1000, '\n');
}
void SoftwareTester::PrintStudent() const {
	student::PrintStudent();
	cout << "Student Address: " << address;
	cout << "\nCity: " << city;
	cout << "\nState: " << state;
	cout << "\nZipcode: " << zipcode << '\n';

}

SoftwareTester SoftwareTester::ValueTest(SoftwareTester test){
	SoftwareTester temp;
	temp = test;
	cout << "\nValue in/out\n";
	return temp;
}
SoftwareTester SoftwareTester::operator=(const SoftwareTester& SWtest){
	SoftwareTester *temp;
	temp = new SoftwareTester (SWtest);
	temp->address = SWtest.address;
	temp->city = SWtest.city;
	temp->state = SWtest.state;
	temp->zipcode = SWtest.zipcode;
	return *temp;
}
ostream& operator<<(ostream& out, SoftwareTester& outStu){
	outStu.PrintStudent();
	return out;
}
