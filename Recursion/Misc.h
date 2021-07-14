/*  Author: Alexander Frederick     *     Misc
 *  Due: 29 November 2017           * CS1C MW 1330-1630
 */

#ifndef MISC_H_
#define MISC_H_

#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <cerrno>
#include <climits>
#include <string.h>
using namespace std;

double cube(double in) {
	return pow(in, 3);
}
double cubeRoot(double in){
	return cbrt(in);
}

void bitRep(char in){
	int bitCount = 0;
	int powCount = 7;
	int temp;
	while(int(in) <= int('z')){
		temp = int(in);
		cout << in << " | " << temp << " | ";
		while(temp > 0){
			if(temp - pow(2, powCount) >=0){
			++bitCount;
			temp -= pow(2, powCount);
			}
			--powCount;
		}
		cout << bitCount << '\n';
		++in;
		if(int(in) == int('[')){
			in+=6;
		}
		bitCount = 0;
		powCount = 7;
	}
}

#endif /* MISC_H_ */
