//============================================================================
// Name        : Alex Frederick
// Assignment  : 2 - Stacks/Queues
// Date        : 2/7/2018
//============================================================================


#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include <iostream>

using namespace std;

template <class Type>
struct nodeType {
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedStackType {
public:
const linkedStackType<Type>& operator=
		(const linkedStackType<Type>&); //overload the assignment operator
void initializeStack(); //Initialize the stack to an empty state.
						//Post condition: Stack elements are removed; top = NULL
bool isEmptyStack();    //Function returns true if the stack is empty;
					    //otherwise, it returns false
bool isFullStack();     //Function returns true if the stack is full;
						//otherwise, it returns false
void push(const Type& newItem); //Add the newItem to the stack.
void pop(Type& poppedElement);  //Remove the top element of the stack.
Type pop(); //Removes the top element and returns its value
Type vTop(); //views the top element of the stack
void destroyStack(); //Remove all elements of the stack, leaving the
					 //stack in an empty state.
linkedStackType();  //default constructor
linkedStackType(const linkedStackType<Type>& otherStack); //copy constructor
~linkedStackType(); //destructor
private:
nodeType<Type> *top; // pointer to the stack
};

template<class Type> //default constructor
linkedStackType<Type>::linkedStackType() {
top = NULL;
}
template<class Type>
void linkedStackType<Type>::destroyStack() {
	nodeType<Type> *temp; //pointer to delete the node
	while(top != NULL) {
		temp = top; 	 //set temp to point to the current node
		top = top->link; //advance top to the next node
		delete temp; 	 //deallocate memory occupied by temp
	}
}// end destroyStack

template<class Type>
Type linkedStackType<Type>::vTop(){
	if(top != NULL)
		return top->info;
	else
		return this->isEmptyStack();
}
template<class Type>
void linkedStackType<Type>:: initializeStack(){
	destroyStack();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack(){
	return(top == NULL);
}

template<class Type>
bool linkedStackType<Type>:: isFullStack(){
	return 0;
}

template<class Type>
void linkedStackType<Type>::push(const Type& newElement){
	nodeType<Type> *newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the node
	newNode->info = newElement; //store newElement in the node
	newNode->link = top; //insert newNode before top
	top = newNode; //set top to point to the top node
} //end push

template<class Type>
void linkedStackType<Type>::pop(Type& poppedElement){
	nodeType<Type> *temp; //pointer to deallocate memory
	poppedElement = top->info; //copy the top element into
	cout << poppedElement;
	temp = top; //set temp to point to the top node
	top = top->link; //advance top to the next node
	delete temp; //delete the top node
}//end pop Void

template<class Type>
Type linkedStackType<Type>::pop(){
	nodeType<Type> *temp; //pointer to deallocate memory
	Type poppedElement = top->info; //copy the top element into
	temp = top; //set temp to point to the top node
	top = top->link; //advance top to the next node
	delete temp; //delete the top node
	return poppedElement;
}//end pop return Type

template<class Type> //copy constructor
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack){
	nodeType<Type> *newNode, *current, *last;
	if(otherStack.top == NULL)
		top = NULL;
	else {
		current = otherStack.top; //set current to point to the
		//stack to be copied
		//copy the top element of the stack
		top = new nodeType<Type>; //create the node
		top->info = current->info; //copy the info
		top->link = NULL; //set the link field of the
		//node to null
		last = top; //set last to point to the node
		current = current->link; //set current to point to the
		//next node
		//copy the remaining stack
		while(current != NULL){
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}//end while
	}//end else
}//end copy constructor

template<class Type> //destructor
linkedStackType<Type>::~linkedStackType(){
	nodeType<Type> *temp;
	while(top != NULL) {
		temp = top; //set temp to point to the current node
		top = top ->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}//end while
}//end destructor

template<class Type> //overloading the assignment operator
const linkedStackType<Type>& linkedStackType<Type>::operator=
(const linkedStackType<Type>& otherStack){
	nodeType<Type> *newNode, *current, *last;
	if(this != &otherStack) {
		if(top != NULL) //if the stack is not empty, destroy it
			destroyStack();
		if(otherStack.top == NULL)
			top = NULL;
		else {
			current = otherStack.top; //set current to point to
			top = new nodeType<Type>; //create the node
			top->info = current->info; //copy the info
			top->link = NULL;
			last = top; //make last point to the node
			current = current->link; //make current point to

while(current != NULL){
	newNode = new nodeType<Type>;
	newNode->info = current->info;
	newNode->link = NULL;
	last->link = newNode;
	last = newNode;
	current = current->link;
	}//end while
	}//end else
	}//end if
	return *this;
}//end operator=

#endif /* SINGLELINKEDLIST_H_ */
