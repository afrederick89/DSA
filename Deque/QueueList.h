//============================================================================
// Name        : Alex Frederick
// Assignment  : 2 - Stacks/Queues
// Date        : 2/7/2018
//============================================================================


#ifndef QUEUELIST_H_
#define QUEUELIST_H_

#include <iostream>

using namespace std;

//Definition of the node
template <class Type>
struct queueNode{
Type info;
queueNode<Type> *link;
};

template<class Type> class linkedQueueType {
public:
	bool isEmptyQueue();
	bool isFullQueue();
	void destroyQueue();
	void initializeQueue();
	void addQueue(const Type& newElement);
	void deQueue(Type& deqElement);
	Type deQueue(); //Returns the data element that is dequeue'd
	linkedQueueType (); //default constructor
	~linkedQueueType(); //destructor
private:
	queueNode<Type> *front; //pointer to the front of the queue
	queueNode<Type> *rear; //pointer to the rear of the queue
};

template<class Type>
linkedQueueType<Type>::linkedQueueType() {
	front = NULL; // set front to null
	rear = NULL; // set rear to null
}

template<class Type>
	bool linkedQueueType<Type>::isEmptyQueue() {
	return(front == NULL);
}

template<class Type>
	bool linkedQueueType<Type>::isFullQueue(){
	return false;
}

template<class Type>
void linkedQueueType<Type>::destroyQueue(){
	queueNode<Type> *temp;
	while(front != NULL) {
		temp = front; // set temp to point to the current node
		front = front ->link; // advance front to the next node
		delete temp; // deallocate memory occupied by temp
	}
	rear = NULL; // set rear to null
}
template<class Type>
void linkedQueueType<Type>::initializeQueue(){
	destroyQueue();
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement){
	queueNode<Type> *newNode;
	newNode = new queueNode<Type>; //create the node
	newNode->info = newElement; //store the info
	newNode->link = NULL; //initialize the link field to null
	if(front == NULL) {
		front = newNode;
		rear = newNode;
	} else {
		rear->link = newNode;
		rear = rear->link;
	}
}//end addQueue

template<class Type>
void linkedQueueType<Type>::deQueue(Type& deqElement) {
	queueNode<Type> *temp;
	deqElement = front->info; //copy the info of the first element
	temp = front; //make temp point to the first node
	front = front->link; //advance front to the next node
	delete temp; //delete the first node
	if(front == NULL) //if after deletion the queue is empty
		rear = NULL; //set rear to NULL
}//end deQueue

template<class Type>
Type linkedQueueType<Type>::deQueue() {
	queueNode<Type> *temp;
	Type deqElement = front->info; //copy the info of the first element
	temp = front; //make temp point to the first node
	front = front->link; //advance front to the next node
	delete temp; //delete the first node
	if(front == NULL) //if after deletion the queue is empty
		rear = NULL; //set rear to NULL
	return deqElement;
}//end deQueue
template<class Type>
linkedQueueType<Type>::~linkedQueueType() {
	queueNode<Type> *temp;
	while(front != NULL) //while there are elements left in the queue
	{
		temp = front; //set temp to point to the current node
		front = front ->link; //advance first to the next node
		delete temp; //deallocate memory occupied by temp
	}
	rear = NULL; // set rear to null
}


#endif /* QUEUELIST_H_ */
