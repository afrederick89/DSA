 /* Author: Alexander Frederick * Students Assignment * Due:6 September 2017
  * CS1C Monday/Wednesday 1330 - 1620
  */
#include "date.h"

	date::date(){
		month = 1;
		day = 1;
		year = 1950;
	};
	date::date(int cMonth, int cDay, int cYear){
		month = cMonth;
		day = cDay;
		year = cYear;
	}
	date::~date(){

	};
	void date::changeDate(int cmonth, int cday, int cyear){
		if(cmonth <= 12 && cmonth >= 1){
			month = cmonth;
		} else {
			cout << "\nInvalid Month\n";
		}
		if(cday <= 31 && cday >= 1) {
			day = cday;
		} else {
			cout << "\nInvalid Day\n";
		}
		if(cyear < 1900) {
			cout << "\nInvalid Year\n";
		} else {
			year = cyear;
		}

	};
	void date::incYear(){
		++year;
	};
	void date::incMonth(){
		if(month < 12){
			++month;
		} else {
			this->incYear();
			month = 1;
		}
	};
	void date::incDay(){
		if (month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12) {
			if(day + 1 > 31){
				this->incMonth();
				day = 1;
			} else {
				++day;
			}
		} else if (month == 2) {
			if(day + 1 > 28) {
				this->incMonth();
				day = 1;
			} else {
				++day;
			}
		} else {
			if(day + 1 > 30){
				this->incMonth();
				day = 1;
			} else {
				++day;
			}
		}

	};
	ostream &operator<<(ostream &out, date obj) {
	        out << obj.month << "/" << obj.day << "/" << obj.year;
	        return out;
	}


