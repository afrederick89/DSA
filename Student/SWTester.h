 /*Author: Alexander Frederick * Students Assignment * Due:9 October 2017
  *CS1C Monday/Wednesday 1330 - 1620
  */

#ifndef SWTESTER_H_
#define SWTESTER_H_
#include "Student.h"
using namespace std;
class SoftwareTester : public student {
public:
	SoftwareTester();
	SoftwareTester(const SoftwareTester&);
	SoftwareTester(string, int, string, int, char, string, float, char*, char*, char*, int);
	~SoftwareTester();
	void ChangeAddress();
	void ChangeCity();
	void ChangeState();
	void ChangeZip();
	SoftwareTester ValueTest(SoftwareTester);
	SoftwareTester operator=(const SoftwareTester&);
	void PrintStudent() const;
	friend ostream& operator<<(ostream& out, SoftwareTester& outStu);

private:
	char* address;
	char* city;
	char* state;
	int zipcode;
};



#endif /* SWTESTER_H_ */
