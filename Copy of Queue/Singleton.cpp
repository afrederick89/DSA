/* Author: Alexander Frederick * Singleton
 * Due: 12 December 2017        * CS1C MW 1330-1620
 */

#include "Singleton.h"

using namespace std;

  bool PrintQueueSingleton::instanceFlag = false;
  PrintQueueSingleton* PrintQueueSingleton::thisQue = NULL;

  PrintQueueSingleton::~PrintQueueSingleton(){
	  instanceFlag = false;
	  delete thisQue;
  }
  PrintQueueSingleton* PrintQueueSingleton::instance(){
	  if(instanceFlag == false){

		  thisQue = new PrintQueueSingleton();
		  instanceFlag = true;
		  cout << "New Singleton created!\n";
		  return thisQue;
	  } else {
		  cout << "\nSingleton Already Exists!";
		  return thisQue;
	  }

  }
	int PrintQueueSingleton::AddJob(string sTextToPrint){
		requests.push_back(sTextToPrint);
		cout << "\nAdded job: " << sTextToPrint;
		return ++jobCount;

	}
	void PrintQueueSingleton::CancelJob(int nJobNumber){
		InvalidRequest invalid;
		if(jobCount == 0){
			cout << "\nNothing in the que.";
		} else {


		try{
			if(requests.size() > nJobNumber){
				requests[nJobNumber].erase();
				cout << "\nCancelled job number: " << nJobNumber;
				--jobCount;
			} else {
				throw invalid;
			}
		}
			catch(InvalidRequest invalid){
				cout << "\nCannot cancel job number: " << nJobNumber
					 << ", no such job exists.\n";
			}

	}
	}
	PrintQueueSingleton::PrintQueueSingleton(){
		jobCount = 0;
	}


