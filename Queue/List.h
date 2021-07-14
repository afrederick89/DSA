/* Author: Alexander Frederick * Linked List
 * Due: 6 November 2017        * CS1C MW 1330-1620
 */

#ifndef LIST_H_
#define LIST_H_
#define MAX_SIZE 10
#include <vector>
#include <iostream>

using namespace std;


template <class Type>
class LinkedList {
public:
	LinkedList();					  	    //constructor
	LinkedList(const LinkedList<Type>& inList);  	//Copy constructor
	~ LinkedList();					  			    //Destructor
	void addNode(Type in, int pos);	//Adds a node
	void nextNode();
	void delNode(int pos);
	Type retdata(int pos);
	int size();					  //Returns number of elements stored
	bool isEmpty();				  //Returns true if empty
	bool isFull();				  //Returns true if full
	void printList();			  //Prints contents of list
	struct Node {
		Type data;
		Node* next;
	};
private:
	int maxSize;				  //Max size value
	Node* start;				  //Points to first element
	Node* index;				  //Index to traverse elements
	int currentSize;			  //Current list size


};

template <class Type>
LinkedList<Type>::LinkedList(){
	maxSize = 5;
	currentSize = 0;
	start = NULL;
	index = NULL;
}
template <class Type>
LinkedList<Type>::~LinkedList(){
	index = start;
	while(currentSize > 0){
		while(index != NULL){
				index = index->next;
			}
		delete index;
		--currentSize;
	}
	delete start;
	start = NULL;
	index = NULL;
}

template <class Type>
void LinkedList<Type>::nextNode() {
	if(index == NULL){
		index = start;
	} else if(index->next == NULL) {
		cout << "\nThere are no more nodes!";
	} else {
		index = index->next;
	}
}
template <class Type>
void LinkedList<Type>::addNode(Type in, int pos) {
	Node* temp;
	Node* prev;
	int i = 0;
	if(start == NULL) {
		start = new Node;
		start->data = in;
		start->next = NULL;
	} else {
		index = start;
		while(i < pos && index->next != NULL){
			prev = index;
			index = index->next;
			++i;
		}
		if(index->next == NULL){
			temp = new Node;
			temp->data = in;
			temp->next = NULL;
			index->next = temp;
			++currentSize;
		} else {
			temp = new Node;
			temp->data = in;
			temp->next = index;
			prev->next = temp;
		}
	}

}
template <class Type>
void LinkedList<Type>::delNode(int pos) {
	Node* temp;
	index = start;
	for(int i = 0; i<pos;++i){
		if(index->next != NULL){
		  temp = index;
		  index = index->next;
		} else {
			cout << "\nNo node at that position!";
		}
	}
	temp->next = index->next;
	delete index;


}
template <class Type>
Type LinkedList<Type>::retdata(int pos){
	index = start;
	for(int i=0;i<pos;++i){
		index = index->next;
	}
	return index->data;
}

template <class Type>
int LinkedList<Type>::size() {
	return currentSize;
}

template <class Type>
bool LinkedList<Type>::isEmpty() {
	bool empty;
	if(currentSize < 1){
		empty = true;
	} else {
		empty = false;
	}
	return empty;
}

template <class Type>
bool LinkedList<Type>::isFull() {
	bool full;
	if(currentSize >= maxSize) {
		full = true;
	} else {
		full = false;
	}
	return full;
}

template <class Type>
void LinkedList<Type>::printList() {
	index = start;
	if(isEmpty()){
		cout << "\nList is Empty!\n";
	} else {
		cout << '\n' << "Printing List: " << index->data << ' ';
		while(index->next != NULL){
			index = index->next;
			cout << index->data << ' ';
		}
	}
}


#endif /* LIST_H_ */
