//============================================================================
// Name        : Alex Frederick
// Assignment  : 2 - Stacks/Queues
// Date        : 2/7/2018
//============================================================================


#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
#include "SingleLinkedList.h"
#include "QueueList.h"
#include "DequeList.h"

using namespace std;

//Parenthesis Algorithm hard coded with given input data

void parenthesis_Algorithm(){
	string expressions[] = {"{2x-8)(12x+6)","{{8x+5)-5x[9x+3]})",
		"{2x+5}(6x+4)", "(((4x+8)-x[4x+3])))","[(5x-5)-4x[6x+2]]",
		"{(8x+5)-6x[9x+3]]","(12x+6)(2x-4)"};
	vector<string> vExp;
	linkedStackType<char> parenStack;
	vExp.insert(vExp.begin(),expressions, expressions+7);

	for(int i=0;i<vExp.size();++i){
		for(int j=0; j<vExp[i].size();++j){
			if(vExp[i][j] == '{')parenStack.push(vExp[i][j]);
			if(vExp[i][j] == '[')parenStack.push(vExp[i][j]);
			if(vExp[i][j] == '(')parenStack.push(vExp[i][j]);

			if(vExp[i][j] == '}' && parenStack.vTop() == '{'){
				parenStack.pop();
			}
			if(vExp[i][j] == ']' && parenStack.vTop() == '['){
				parenStack.pop();
			}
			if(vExp[i][j] == ')' && parenStack.vTop() == '('){
				parenStack.pop();
			}
		}
		if(parenStack.isEmptyStack()){
			cout << vExp[i] << " is valid!\n";
		} else {
			cout << vExp[i] << " is NOT valid!\n";
		}
		parenStack.destroyStack();
	}
}
#endif /* CLIENT_H_ */
