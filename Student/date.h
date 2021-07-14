 /* Author: Alexander Frederick * Students Assignment *Due: 6 September 2017
  * CS1C Monday/Wednesday 1330 - 1620
  */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
using namespace std;

class date {
public:
	date();
	date(int month, int day, int year);
	~date();
	void changeDate(int month, int day, int year);
	void incYear();
	void incMonth();
	void incDay();
	friend ostream &operator<<(ostream &out, date obj);
private:
	 int month;
	 int day;
	 int year;
};




#endif /* DATE_H_ */
