//============================================================================
// Name        : Alex Frederick
// Assignment  : 2 - Stacks/Queues
// Date        : 2/7/2018
//============================================================================
/****************************************************************************
 * This Program displays the following elements:
 * STL<stack>, non-STL Stack using a singly linked list, a linked list queue,
 * and a linked list deque.
 * Each element receives the same data set, displays the data set, and has
 * elements deleted.
 *
 * In a separate use, the parenthesis algorithm is available.  The algorithm
 * displays the validity of mathematical equations by evaluating for correct
 * parenthetical placements.
 ****************************************************************************/

#include "client.h"

int main() {


	string names[] = {"Mark", "Alan", "Rick", "Eric",
			 "Jennifer", "JoAnn", "Bill"};
	double dbls[] = {44.44, 888.55, 88.88, 123.123, 8.445,
					   983.3};
	bool found; 			// Bool used for search
	string popString;		// Element used for pop
	double popDouble;		// Element used for pop
	linkedStackType<string> linkNameStack;	//Stack based on linked list
	linkedStackType<double> linkDblStack;	//Stack based on linked list
	linkedQueueType<string> linkNameQueue;	//Queue based on linked list
	linkedQueueType<double> linkDblQueue;	//Queue based on linked list
	LinkedDeque<string> 	linkNameDeque;	//Deque based on linked list
	LinkedDeque<double>		linkDblDeque;	//Deque based on linked list

	vector<string> vNames;	//Vector containing the input data
	vector<double> vDbls;	//Vector containing the input data

	cout << "***************************************************************\n"
			"Name        : Alex Frederick\n"
			"Assignment  : 2 - Stacks/Queues\n"
			"Date        : 2/7/2018\n"
			"***************************************************************\n";
	vNames.insert(vNames.begin(), names, names+7); //Vectors initialized
	vDbls.insert(vDbls.begin(), dbls, dbls+6);

	//STL-Stack Initialize
	stack<string, vector<string> > nameStack(vNames); //STL-Stack
	stack<double, vector<double> > dblStack(vDbls);	  //STL-Stack

	cout << "Part A: STL<stack>\nName Stack: ";
	while(!nameStack.empty()){
		cout << nameStack.top() << ' ';
		nameStack.pop();
	}
	cout << "\nDouble Stack: ";
	while(!dblStack.empty()){
			cout << dblStack.top() << ' ';
			dblStack.pop();
	}
	//STL-Stack initialized after full display
	for(int i=0;i<vNames.size();++i)
		nameStack.push(vNames[i]);
	for(int i=0;i<vDbls.size();++i)
		dblStack.push(vDbls[i]);
	//Search for name in stack, pop if not found and search again.
	found = false;
	while(!found && !nameStack.empty()){
		if(nameStack.top() != "Rick"){
			nameStack.pop();
		} else {
			nameStack.pop();
		    found = true;
		}
	}
	//Search for double in stack, pop if not found and search again.
	found = false;
	while(!found && !dblStack.empty()){
		if(dblStack.top() != 88.88){
			dblStack.pop();
		} else {
			dblStack.pop();
		    found = true;
		}
	}
	//Output Remaining values in stack
	cout << "\nPart B: Delete Rick and 88.88\nName Stack: ";
	while(!nameStack.empty()){
		cout << nameStack.top() << ' ';
		nameStack.pop();
	}
	cout << "\nDouble Stack: ";
	while(!dblStack.empty()){
		cout << dblStack.top() << ' ';
		dblStack.pop();
	}
	//Linked List Stack is initialized
	for(int i=0;i<vNames.size();++i)
			linkNameStack.push(vNames[i]);
	for(int i=0;i<vDbls.size();++i)
			linkDblStack.push(vDbls[i]);
	//Part C- Printing Linked List Stack
	cout << "\n\nPart C: Singly Linked List Stack \nName Stack: ";
	while(!linkNameStack.isEmptyStack()){
		linkNameStack.pop(popString);
		cout << ' ';
	}
	cout << "\nDouble Stack: ";
	while(!linkDblStack.isEmptyStack()){
			linkDblStack.pop(popDouble);
					cout << ' ';
	}
	//Re-initalize linked list stack
	for(int i=0;i<vNames.size();++i){
		linkNameStack.push(vNames[i]);
	}
	for(int i=0;i<vDbls.size();++i){
		linkDblStack.push(vDbls[i]);
	}
	//Search through stack for name, pop until found or empty stack
	found = false;
	while(!found && !linkNameStack.isEmptyStack()){
		if(linkNameStack.pop() == "Rick"){
			found = true;
			linkNameStack.pop();
		}
	}
	found = false;
	while(!found && !linkDblStack.isEmptyStack()){
		if(linkDblStack.pop() == 88.88){
			found = true;
			linkDblStack.pop();
		}
	}
	//Print values remaining in linked list stack
	cout << "\nPart D: Delete Rick/88.88 from List Stack\nName Stack: ";
	while(!linkNameStack.isEmptyStack()){
		linkNameStack.pop(popString);
		cout << ' ';
	}
	cout << "\nDouble Stack: ";
	while(!linkDblStack.isEmptyStack()){
			linkDblStack.pop(popDouble);
					cout << ' ';
	}
	//Initialize Linked list queue
	for(int i=0;i<vNames.size();++i){
		linkNameQueue.addQueue(vNames[i]);
	}
	for(int i=0;i<vDbls.size();++i){
		linkDblQueue.addQueue(vDbls[i]);
	}
	//Print Linked List queue
	cout << "\n\nPart E: Linked List Queue \nName Queue: ";
	while(!linkNameQueue.isEmptyQueue()){
		cout << linkNameQueue.deQueue() << ' ';
	}
	cout << "\nDouble Queue: ";
	while(!linkDblQueue.isEmptyQueue()){
		cout << linkDblQueue.deQueue() << ' ';
	}
	//Re-initalize Linked List Queue
	for(int i=0;i<vNames.size();++i){
		linkNameQueue.addQueue(vNames[i]);
	}
	for(int i=0;i<vDbls.size();++i){
		linkDblQueue.addQueue(vDbls[i]);
	}
	//Search for delete value, deque until found
	found = false;
	while(!found && !linkNameQueue.isEmptyQueue()){
		if(linkNameQueue.deQueue() == "Rick"){
			found = true;
		}
	}
	found = false;
	while(!found && !linkDblQueue.isEmptyQueue()){
		if(linkDblQueue.deQueue() == 88.88){
			found = true;
		}
	}
	//Print remaining values in Linked List queue
	cout << "\nPart F: Delete Rick/88.88 from List Queue\nName Queue: ";
	while(!linkNameQueue.isEmptyQueue()){
		cout << linkNameQueue.deQueue() << ' ';
	}
	cout << "\nPart F: Double Queue: ";
	while(!linkDblQueue.isEmptyQueue()){
		cout << linkDblQueue.deQueue() << ' ';
	}
	//Initialize Linked List Deque
	for(int i=0;i<vNames.size();++i){
		linkNameDeque.insertFront(vNames[i]);
	}
	for(int i=0;i<vDbls.size();++i){
		linkDblDeque.insertFront(vDbls[i]);
	}
	//Print Linked List Deque
	cout << "\n\nPart G: Linked List Deque \nName Deque: ";
	while(!linkNameDeque.empty()){
		cout << linkNameDeque.pop_front() << ' ';
	}
	cout << "\nDouble Deque: ";
	while(!linkDblDeque.empty()){
		cout << linkDblDeque.pop_back() << ' ';
	}
	//Re-initialize Linked List Deque
	for(int i=0;i<vNames.size();++i){
		linkNameDeque.insertFront(vNames[i]);
	}
	for(int i=0;i<vDbls.size();++i){
		linkDblDeque.insertFront(vDbls[i]);
	}
	//Search Linked List Deque, string Deque pop_front,
	// 							double Deque pop_back
	found = false;
	while(!found && !linkNameDeque.empty()){
		if(linkNameDeque.pop_front() == "Rick"){
			found = true;
		}
	}
	found = false;
	while(!found && !linkDblDeque.empty()){
		if(linkDblDeque.pop_back() == 88.88){
			found = true;
		}
	}
	//Print remaining values in Linked List Deque
	cout << "\nPart H: Delete Rick(pop_front) and 88.88(pop_back)\nName Deque: ";
	while(!linkNameDeque.empty()){
		cout << linkNameDeque.pop_front() << ' ';
	}
	cout << "\nDouble Deque: ";
	while(!linkDblDeque.empty()){
		cout << linkDblDeque.pop_back() << ' ';
	}
	//Parenthesis Algorithm
	cout << "\n\nPart I: Parentheses algorithm:\n";
	parenthesis_Algorithm();
	return 0;
}


