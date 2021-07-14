 /*Author: Alexander Frederick * Students Assignment * Due:6 September 2017
  *CS1C Monday/Wednesday 1330 - 1620
  */

#ifndef CS1CSTUDENT_H_
#define CS1CSTUDENT_H_

#include "Student.h"
#include "date.h"

class cs1cStudent : public student {
public:
	cs1cStudent();
	cs1cStudent(string sName, int sID, string sPhNum, int sAge,
			    char sGender,  string sStanding, float sGpa, int sScore,
				string sPythKnow, int cMonth, int cDay, int cYear);
	~cs1cStudent();
	void ChangeScore();
	void ChangeKnowl();
	void ChangeGradDate();
	void PrintStudent() const;

private:
	int score;
	string pythKnow;
	date gradDate;
};



#endif /* CS1CSTUDENT_H_ */
