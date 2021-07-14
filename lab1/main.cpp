//============================================================================
// Name        : Lab1_Vectors_RandomNum.cpp
// Author      : Alex Frederick & Samantha Finks
// Assignment  : Lab 1 - Vectors
// Date        : 1/17/2018
//============================================================================

/******************************************************************************
 * This program will generate 15 random numbers and store them in a vector.
 * The program will then sort the numbers and enter them into another vector
 * in reverse order.  Then the digits of each number will be summed and stored
 * into the final vector.
 * The vectors will then all be output.
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    vector<int> randomV(15);    //Random Number Vector
    vector<int> reverseV(15);    //Reversed number value vector
    vector<int> sumV(15);        //Sum of the digits vector
    int randomNum = 0;            //Random Number storage
    int sum;                    //Sum storage
    int temp;                    //Temp for mod value
    int temp2;                    //Temp for mod value
    int temp3;                    //Temp for mod value
    string tempChar;

    srand(time(NULL));
    cout << "============================================================================\n"
         << "Name        : Lab1_Vectors_RandomNum.cpp\n"
         << "Author      : Alex Frederick & Samantha Finks\n"
         << "Assignment  : Lab 1 - Vectors\n"
         << "============================================================================\n"

         <<"*******************************************************************************\n"
         <<"* This program will generate 15 random numbers and store them in a vector.\n"
         <<"* The program will then sort the numbers and enter them into another vector\n"
         <<"* in reverse order.  Then the digits of each number will be summed and stored\n"
         <<"* into the final vector.\n"
         <<"* The vectors will then all be output.\n"
         <<"*******************************************************************************\n" << endl;

    //Stores initial random values
    for(int i=0; i < 15; i++)
    {
        randomNum = rand() % 999 + 1;
        if(randomNum < 100)
        	randomNum += 100;
        randomV[i] = randomNum;
    }
    //Sorts random values
    sort(randomV.begin(), randomV.end());
    for(int i=0;i<15;++i){
        cout << "Random number at position " << i << ": " << randomV[i] << endl;
    }
    randomV[0] = 200;
    cout << '\n';

    //Reverses the random numbers and stores in reverse vector
    for(int i=0; i < 15; i++)
    {
        temp =  randomV[i] % 10;
        temp2 = randomV[i] / 10 % 10;
        temp3 = randomV[i] / 100 % 10;
        temp3 = temp3 + (temp * 100) + (temp2 * 10);

        reverseV[i] = temp3;
    }

    //Sums the digits together and stores them in sum vector
    for(int i=0; i < 15; i++)
    {
        sum = 0;
        temp = randomV[i] % 10;
        temp2 = randomV[i] / 10 % 10;
        temp3 = randomV[i] / 100 % 10;
        sum = temp + temp2 + temp3;

        sumV[i] = sum;
    }

    //Outputs the Sum values
    for(int i=0;i<15;++i){
        cout << "The sum of the digits " << randomV[i] << " is "
             << sumV[i] << endl;
    }
    cout << '\n';

    //Outputs the reverse values
    for(int i=0;i<15;++i){
        cout << "The reverse of the digits " << randomV[i] << " is "
        	 << setw(3) << setfill ('0') << reverseV[i] << endl;
    }

    return 0;
}
