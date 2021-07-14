//============================================================================
// Name        : Alex Frederick
// Assignment  : 5 - Hash Map
// Date        : 3/7/2018
//============================================================================
/****************************************************************************
 * This Program implements 2 hash maps. One using a double hashing algorithm
 * and one using a quadratic hashing algorithm.  Each uses a vector as a bucket
 * and a map as the data structure.
 *
 ****************************************************************************/

#include "main.h"

int main() {

	cout << "***************************************************************\n"
				"Name        : Alex Frederick\n"
				"Assignment  : 5 - Hash Map\n"
				"Date        : 3/7/2018\n"
				"***************************************************************\n";
		cout << "***************************************************************\n"
				"* This Program implements 2 hash maps. One using a double hashing\n"
				"* algorithm and one using a quadratic hashing algorithm.  Each\n"
				"* uses a vector as a bucket and a map as the data structure.\n"
				"***************************************************************\n";
	HashMap<int, string> mapPartOne;
	HashMapPtTwo<int, string> mapPartTwo;
	mapPartOne.put(18, "Mission Viejo");
	mapPartOne.put(41, "Laguna Niquel");
	mapPartOne.put(22, "San Clemente");
	mapPartOne.put(44, "Irvine");
	mapPartOne.erase(41);
	mapPartOne.put(58, "Lake Forest");
	mapPartOne.put(32, "San Diego");
	mapPartOne.put(44, "Anaheim");
	mapPartOne.erase(58);
	mapPartOne.put(31, "Los Angeles");
	mapPartOne.put(17, "Orange");
	mapPartOne.put(72, "Palm Springs");
	mapPartOne.put(41, "Riverside");
	mapPartOne.erase(49);
	mapPartOne.put(19, "Brea");
	mapPartOne.put(60, "Santa Ana");
	mapPartOne.put(35, "Tustin");
	mapPartOne.put(103, "Oceanside");
	mapPartOne.put(11, "La Jolla");
	mapPartOne.put(18, "Del Mar");
	mapPartOne.put(22, "Aliso Viejo");
	mapPartOne.put(49, "Laguna Beach");
	mapPartOne.erase(41);
	mapPartOne.put(42, "Vista");
	mapPartOne.put(49, "San Diego");
	mapPartOne.put(99, "San Juan");
	mapPartOne.put(29, "Dana Point");
	mapPartOne.put(88, "El Segundo");
	mapPartOne.put(41, "San Clemente");
	mapPartOne.put(62, "Laguna Hills");
	cout << "Using double hash, Map and Vector: \n";
	mapPartOne.print();

	mapPartTwo.put(18, "Mission Viejo");
	mapPartTwo.put(41, "Laguna Niquel");
	mapPartTwo.put(22, "San Clemente");
	mapPartTwo.put(44, "Irvine");
	mapPartTwo.erase(41);
	mapPartTwo.put(58, "Lake Forest");
	mapPartTwo.put(32, "San Diego");
	mapPartTwo.put(44, "Anaheim");
	mapPartTwo.erase(58);
	mapPartTwo.put(31, "Los Angeles");
	mapPartTwo.put(17, "Orange");
	mapPartTwo.put(72, "Palm Springs");
	mapPartTwo.put(41, "Riverside");
	mapPartTwo.erase(49);
	mapPartTwo.put(19, "Brea");
	mapPartTwo.put(60, "Santa Ana");
	mapPartTwo.put(35, "Tustin");
	mapPartTwo.put(103, "Oceanside");
	mapPartTwo.put(11, "La Jolla");
	mapPartTwo.put(18, "Del Mar");
	mapPartTwo.put(22, "Aliso Viejo");
	mapPartTwo.put(49, "Laguna Beach");
	mapPartTwo.erase(41);
	mapPartTwo.put(42, "Vista");
	mapPartTwo.put(49, "San Diego");
	mapPartTwo.put(99, "San Juan");
	mapPartTwo.put(29, "Dana Point");
	mapPartTwo.put(88, "El Segundo");
	mapPartTwo.put(41, "San Clemente");
	mapPartTwo.put(62, "Laguna Hills");
	cout << "Part 2: Using Quadratic hash and Vector Buckets\n";
	mapPartTwo.print();
	return 0;


}



