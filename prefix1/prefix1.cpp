//============================================================================
// Name        : Lab 3 - Prefix averages
// Author      : Alex Frederick
// Assignment  : Lab 3 - Prefix averages
// Date        : 1/29/2018
//============================================================================

/******************************************************************************
 * This program will complete an algorithm in O(n^2) or at a quadratic growth
 * rate the program is measured by the clock() function and will output the
 * length of time required to complete the algorithm
 *****************************************************************************/
#include <ctime>
#include <iostream>

using namespace std;

int main(){
	const int SIZE = 20000;
	int X[SIZE];
	int A[SIZE];
	int a;
	clock_t ticks;
	ticks = clock();
	cout << ticks << " nanoseconds used by the processor.\n";
	for(int i=0;i<SIZE-1;++i){
		X[i] = (i+10);
		a=0;
		for(int j=0;j<=i;++j){
			a+=X[j];
		}
		A[i] = a / (i+1);
	}
	ticks = double(ticks)+clock();
	cout << ticks << " nanoseconds used by the processor.\n";
	for(int i=0;i<3;++i){
		cout << "X Array:" << X[i] << '\n';
		cout << "A Array(AVG): " << A[i] << '\n';
	}

	return 0;
}
