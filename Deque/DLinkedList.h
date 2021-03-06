//============================================================================
// Name        : Alex Frederick
// Assignment  : 2 - Stacks/Queues
// Date        : 2/7/2018
//============================================================================


#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <iostream>

using namespace std;

template <class Type>
struct dLinkNode {
	Type info;
	dLinkNode<Type> *next;
	dLinkNode<Type> *prev;
};

template <class Type> class DLinkedList { // doubly linked list
public:
	DLinkedList(); // constructor
	~DLinkedList(); // destructor
	bool empty() const; // is list empty?
	const Type& front() const; // get front element
	const Type& back() const; // get back element
	void addFront(const Type& e); // add to front of list
	void addBack(const Type& e); // add to back of list
	void removeFront(); // remove from front
	void removeBack(); // remove from back
private: // local type definitions
	dLinkNode<Type>* header; // list sentinels
	dLinkNode<Type>* trailer;
protected: // local utilities
	void add(dLinkNode<Type>* v, const Type& e); // insert new node before v
	void remove(dLinkNode<Type>* v); // remove node v
};

template <class Type>
DLinkedList<Type>::DLinkedList() { // constructor
	header = new dLinkNode<Type>; // create sentinels
	trailer = new dLinkNode<Type>;
	header->next = trailer; // have them point to each other
	trailer->prev = header;
}
template <class Type>
DLinkedList<Type>::~DLinkedList() { // destructor
	while (!empty()) removeFront(); // remove all but sentinels
	delete header; // remove the sentinels
	delete trailer;
}
template <class Type>
bool DLinkedList<Type>::empty() const // is list empty?
{ return (header->next == trailer); }

template <class Type>
const Type& DLinkedList<Type>::front() const // get front element
{ return header->next->info; }

template <class Type>
const Type& DLinkedList<Type>::back() const // get back element
{ return trailer->prev->info; }

template <class Type>
void DLinkedList<Type>::add(dLinkNode<Type>* v, const Type& e) {
	dLinkNode<Type>* u = new dLinkNode<Type>;
	u->info = e; // create a new node for e
	u->next = v; // link u in between v
	u->prev = v->prev; // ...and v->prev
	v->prev->next = v->prev = u;
}
template <class Type>
void DLinkedList<Type>::addFront(const Type& e) // add to front of list
{ add(header->next, e); }

template <class Type>
void DLinkedList<Type>::addBack(const Type& e) // add to back of list
{ add(trailer, e); }

template <class Type>
void DLinkedList<Type>::remove(dLinkNode<Type>* v) { // remove node v
	dLinkNode<Type>* u = v->prev; // predecessor
	dLinkNode<Type>* w = v->next; // successor
	u->next = w; // unlink v from list
	w->prev = u;
	delete v;
}

template <class Type>
void DLinkedList<Type>::removeFront() // remove from font
{ remove(header->next); }

template <class Type>
void DLinkedList<Type>::removeBack() // remove from back
{ remove(trailer->prev); }
#endif /* DLINKEDLIST_H_ */
