/*  Author: Alexander Frederick     *     Misc
 *  Due: 29 November 2017            * CS1C MW 1330-1630
 */
#include "Misc.h"


int main(){
	time_t rawtime;
	tm *currentTime;
	tm compTimeA = {0,0,0,24,11,117};
	tm compTimeB = {0,0,0,25,6,117};
	mktime(&compTimeA);
	mktime(&compTimeB);
	time(&rawtime);
	currentTime = localtime(&rawtime);
	errno = 0;
	double (*cubePT)(double);
	double (*cRootPT)(double);
	cubePT = cube;
	cRootPT = cubeRoot;



	cout << "Current Date: ";
	cout << currentTime->tm_mday << "/"
	     << currentTime->tm_mon + 1 << "/"
		 << currentTime->tm_year + 1900;

	cout << "\n108 Days from today: ";
	currentTime->tm_mday = currentTime->tm_mday + 108;
	mktime(currentTime);
	cout << currentTime->tm_mday << "/"
		 << currentTime->tm_mon + 1 << "/"
		 << currentTime->tm_year + 1900;

	cout << "\nNumber of days between July 25 and Dec 24: ";
	cout << compTimeA.tm_yday - compTimeB.tm_yday;

	sqrt(-2);
	cout << "\nSquare root of -2 error: " << strerror(errno);
	errno = 0;
	tan(90.0);
	cout << "\nDivide by zero error: " << strerror(errno);
	errno = 0;
	log(-2);
	cout << "\nNatural log of -2 error: " << strerror(errno);
	errno = 0;
	cout << "\n1x10^19 + 4 - 1x10^19: "
		 << pow(10.0, 19.0) - pow(10.0, 19.0) + 4;

	cout << "\nCube of 2.5 function pointer: " << (*cubePT)(2.5);
	cout << "\nCube root of 8.0 function pointer: " << (*cRootPT)(8.0)
		 << '\n';

	bitRep('A');

	return 0;

}

