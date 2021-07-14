/* Author: Alexander Frederick * Linked List
 * Due: 6 November 2017        * CS1C MW 1330-1620
 */

#include "iostream"
#include "List.h"

using namespace std;

int main() {
	int count;
	double val = 2.58;
	LinkedList<int> myIntList;
	LinkedList<int> secondIntList;
	LinkedList<double> firstDblList;
	LinkedList<double> secondDblList;
	cout << "Int's: ";
	myIntList.addNode(88, 0);
	myIntList.addNode(78, 1);
	myIntList.addNode(62, 2);
	myIntList.addNode(123, 3);
	myIntList.addNode(60, 4);
	myIntList.printList();
	count = 4;
	for(int i = 0; i < 5;++i){
		secondIntList.addNode(myIntList.retdata(count), i+1);
		--count;
	}
	secondIntList.printList();
	myIntList.delNode(2);
	secondIntList.delNode(2);
	myIntList.printList();
	secondIntList.printList();
	myIntList.addNode(70, 2);
	secondIntList.addNode(70, 2);
	myIntList.printList();
	secondIntList.printList();

	cout << "\nDoubles: ";
	for(int i=0;i<5;++i){
		firstDblList.addNode(val, i+1);
		val += 1.33;
	}
	count = 4;
	for(int i=0;i<5;++i){
		secondDblList.addNode(firstDblList.retdata(count),i+1);
		--count;
	}
	firstDblList.printList();
	secondDblList.printList();
	firstDblList.delNode(2);
	secondDblList.delNode(2);
	firstDblList.printList();
	secondDblList.printList();
	firstDblList.addNode(val, 2);
	secondDblList.addNode(val, 2);
	firstDblList.printList();
	secondDblList.printList();
	return 0;
}



