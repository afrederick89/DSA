//============================================================================
// Name        : Alex Frederick
// Assignment  : Extra Credit - Wrapper
// Date        : 2/7/2018
//============================================================================


#ifndef DEQUELIST_H_
#define DEQUELIST_H_

#include "DLinkedList.h"

template<class Type> class LinkedDeque { // deque as doubly linked list
public:
LinkedDeque(); // constructor
	int size(); // number of items in the deque
	bool empty(); // is the deque empty?
	const Type& front(); // the first element
	const Type& back(); // the last element
	void insertFront(const Type& e); // insert new first element
	void insertBack(const Type& e); // insert new last element
	Type pop_front(); //returns the element popped from front
	Type pop_back(); // returns the element popped from back
	void removeFront(); // remove first element
	void removeBack(); // remove last element
private: // member data
	DLinkedList<Type> D; // linked list of elements
	int n; // number of elements
};
template<class Type>
int LinkedDeque<Type>::size(){
	return D.size();
}
template<class Type>
LinkedDeque<Type>::LinkedDeque(){
	n = 0;
}
template<class Type>
void LinkedDeque<Type>::insertFront(const Type& e) {
	D.addFront(e);
	cout << "Inserting " << e << " to front.\n";
	n++;
}
template<class Type>
bool LinkedDeque<Type>::empty(){
	return D.empty();
}
// insert new last element
template<class Type>
void LinkedDeque<Type>::insertBack(const Type& e) {
	D.addBack(e);
	cout << "Inserting " << e << " to back.\n";
	n++;
}
// remove first element
template<class Type>
void LinkedDeque<Type>::removeFront(){
	if (this->empty())
		cout << "\nEmpty Deque\n";
	D.removeFront();
	cout << "Removing front.\n";
	n--;
}
template<class Type>
Type LinkedDeque<Type>::pop_front(){
	Type temp;
	temp = D.front();
	D.removeFront();
	cout << "Removing " << temp << " from front.\n";
	n--;
	return temp;
}
template<class Type>
Type LinkedDeque<Type>::pop_back() {
	Type temp;
	temp = D.back();
	D.removeBack();
	cout << "Removing " << temp << " from back.\n";
	n--;
	return temp;
}
// remove last element
template<class Type>
void LinkedDeque<Type>::removeBack() {
	if (this->empty())
		cout << "\nEmpty Deque\n";
	D.removeBack();
	cout << "Removing from back.\n";
	n--;
}
template<class Type>
const Type& LinkedDeque<Type>::front() {
	return D.front();
}

#endif /* DEQUELIST_H_ */
