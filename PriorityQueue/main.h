//============================================================================
// Name        : Alex Frederick
// Assignment  : 5 - Priority Queue
// Date        : 2/28/2018
//============================================================================
/****************************************************************************
 * This file contains the structure of the patient data, and the comparator
 *
 ****************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <time.h>
#include "prioQADT.h"
using namespace std;

class patient {
public:
	string name;
	double waitTime;
	int treatTime;
	patient(string x, double y){name=x;waitTime=y;treatTime=25;}
	void newPatient(string x, double y){name=x;waitTime=y;treatTime=25;}
};

class myComp{
public:
	bool operator()(patient& p, patient& q) const
	{ return p.waitTime < q.waitTime;}
};

#endif /* MAIN_H_ */
