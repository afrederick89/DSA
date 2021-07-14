//============================================================================
// Name        : Alex Frederick
// Assignment  : 3 - Vector ADT
// Date        : 2/14/2018
//============================================================================
/****************************************************************************
 * This Program implements an extendable array. Each insert/delete will display
 * the value being inserted/deleted and at what position within the array.
 *
 ****************************************************************************/
#include "VectorAdt.h"


int main(){
	ArrayVector<int> myVect;

	cout << "***************************************************************\n"
			"Name        : Alex Frederick\n"
			"Assignment  : 3 - Vector ADT\n"
			"Date        : 2/14/2018\n"
			"***************************************************************\n";
	cout << "***************************************************************\n"
			"* This Program implements an extendable array. Each\n"
			"* insert/delete will display the value being\n"
			"* inserted/deleted and at what position within the array.\n"
			"***************************************************************\n";
	cout << "\n\nTesting Inserts:\n";
	myVect.insert(0, 1);
	myVect.printV();
	myVect.insert(1, 2);
	myVect.printV();
	myVect.insert(2, 3);
	myVect.printV();
	myVect.insert(0, 4);
	cout <<"\nTesting Size: \n";
	cout << myVect.size() << '\n';
	cout << "\nTest Erase(out of bounds first): \n";
	myVect.erase(5);
	myVect.erase(4);
	myVect.printV();
	cout <<"\nTesting .at() (out of bounds first):\n";
	myVect.at(8);
	myVect.at(3);
	myVect.erase(0);
	cout << "\nIs Empty (Returns bool value):\n";
	cout << "IsEmpty: " << myVect.empty() << '\n';
	myVect.erase(0);
	myVect.printV();
	myVect.erase(0);
	myVect.printV();
	cout << "IsEmpty: " << myVect.empty() << '\n';
	cout << "\nTesting reserve, using 10:\n";
	myVect.reserve(10);
	cout << "\nTesting reserve, using 8(should do nothing):\n";
	myVect.reserve(8);

	return 0;

}

