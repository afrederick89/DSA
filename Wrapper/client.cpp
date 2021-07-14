//============================================================================
// Name        : Alex Frederick
// Assignment  : Extra Credit - Wrapper
// Date        : 2/7/2018
//
//  This Program is an implementation of a wrapper.  It wraps a Deque over a
//  Doubly Linked List class.  The output currently displays the methods in
//  use
//============================================================================



#include "DLinkedList.h"
#include "DequeList.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string string1 = "A man, a plan, a canal, Panama";
    string string2 = "Was it a car or a cat I saw?";
    string string3 = "Sit on a potato pan, Otis";
    string string4 = "No lemon, no melon";
    cout << "***************************************************************\n"
			"Name        : Alex Frederick\n"
			"Assignment  : Extra Credit - Wrapper\n"
			"Date        : 2/7/2018\n"
			"***************************************************************\n";
    cout << "This Program is an implementation of a wrapper.\n"
    		"It wraps a Deque over a Doubly Linked List class.\n"
    		"The output currently displays the methods in use\n\n";
    LinkedDeque<string> testDeque;
    cout << "Initial Deque size: " << testDeque.size();
    cout << "\nInitial Deque Empty(1/0 true/false): " << testDeque.empty()
    	 << '\n';
    testDeque.insertFront(string1);
    testDeque.insertFront(string2);
    testDeque.insertBack(string3);
    testDeque.insertBack(string4);
    cout << "\nDeque front: " << testDeque.front() << '\n';
    testDeque.removeFront();
    cout << "\nDeque front after remove (1): " << testDeque.front();
    cout << "\nSecondary Deque size: " << testDeque.size() << '\n';
    while(!testDeque.empty()){
    	testDeque.removeBack();
    }
    cout << "\nEmptied Deque: " << testDeque.empty();
	return 0;
}
