//============================================================================
// Name        : Alex Frederick
// Assignment  : 5 - Priority Queue
// Date        : 2/28/2018
//============================================================================
/****************************************************************************
 * This Program implements 2 Priority Queues, one from the Standard Template
 * Library. One from the author's priority queue adt.  All the elements will
 * be inserted at the beginning and the scenario will be ran.
 *
 * Scenario: Emergency room patients each get 25 minutes of treatment time.
 * If a life threatening patient comes in, that patient immediately gets
 * treatment, and then the previous patient will recieve the remaining
 * treatment time.
 *
 ****************************************************************************/
#include "main.h"

int main(){
	cout << "***************************************************************\n"
			"Name        : Alex Frederick\n"
			"Assignment  : 5 - Priority Queue\n"
			"Date        : 2/28/2018\n"
			"***************************************************************\n";
	cout << "***************************************************************\n"
			"* This Program implements 2 Priority Queues, one from the\n"
			"* Standard Template Library. One from the author's priority queue\n"
			"* adt. All the elements will be inserted at the beginning and the\n"
			"* scenario will be ran.\n"
			"* Scenario: Emergency room patients each get 25 minutes of \n"
			"* treatment time. If a life threatening patient comes in, that\n"
			"* patient immediately gets treatment, and then the previous\n"
			"* patient will recieve the remaining treatment time.\n"
			"***************************************************************\n";
	vector<patient> patients;
	priority_queue<patient, vector<patient>, myComp> myprioQ;
	AdaptPriorityQueue<patient, myComp> adtQue;
	time_t cTime;
	patient currentPatient("NA", 0);
	struct tm timer = {0};
	timer.tm_hour = 12;
	time(&cTime);
	int waitTimer = 0;
	patient temp("Bob Bleeding", 2);
	myprioQ.push(temp);
	adtQue.insert(temp);
	temp.newPatient("Frank Feelingbad", 3);
	myprioQ.push(temp);
	adtQue.insert(temp);
	temp.newPatient("Cathy Coughing", 5);
	myprioQ.push(temp);
	adtQue.insert(temp);
	temp.newPatient("Paula Pain", 4);
	myprioQ.push(temp);
	adtQue.insert(temp);
	temp.newPatient("Alice Ailment", 7);
	myprioQ.push(temp);
	adtQue.insert(temp);
	temp.newPatient("Irene Ill", 1);
	myprioQ.push(temp);
	adtQue.insert(temp);
	temp.newPatient("Tom Temperature", 6);
	myprioQ.push(temp);
	adtQue.insert(temp);
	cout << "STL Version: \n";
	currentPatient = myprioQ.top();
	cout << "Start: " << currentPatient.name << " at "
		 << timer.tm_hour << ":";
		 if(timer.tm_min < 10){
			 cout << "0" << timer.tm_min;
		 } else {
			 cout << timer.tm_min;
		 }
	while(!myprioQ.empty()){

		if(timer.tm_hour == 13 && timer.tm_min == 12){
			temp.newPatient("Sam Sneezing", 50);
			myprioQ.pop();
			myprioQ.push(temp);
			myprioQ.push(currentPatient);
			currentPatient = myprioQ.top();
			cout << "\nLIFE THREAT: " << currentPatient.name << " at "
				 << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min;
				 } else {
					 cout << timer.tm_min;
				 }
			waitTimer = 0;
		}
		if(timer.tm_hour == 14 && timer.tm_min == 1){
			temp.newPatient("Sid Sickly", 50);
			myprioQ.pop();
			myprioQ.push(temp);
			myprioQ.push(currentPatient);
			currentPatient = myprioQ.top();
			cout << "\nLIFE THREAT: " << currentPatient.name << " at "
				 << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min;
				 } else {
					 cout << timer.tm_min;
				 }
			waitTimer = 0;
		}
		if(currentPatient.treatTime == 0){
			temp = myprioQ.top();
			cout <<  " completed at " << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min << endl;
				 } else {
					 cout << timer.tm_min << endl;
				 }
			myprioQ.pop();
			if(!myprioQ.empty()){
			currentPatient = myprioQ.top();

			cout << "Start: " << currentPatient.name << " at "
				 << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min;
				 } else {
					 cout << timer.tm_min;
				 }
			}
			waitTimer = 0;
		}
		timer.tm_min++;
		waitTimer++;
		--currentPatient.treatTime;
		if(timer.tm_min == 60){
			timer.tm_min = 0;
			timer.tm_hour++;
		}
	}
    timer.tm_hour = 12;
    timer.tm_min = 0;
    waitTimer = 0;
    cout << "\nADT VERSION: \n";
 currentPatient = adtQue.top();
	cout << "Start: " << currentPatient.name << " at "
		 << timer.tm_hour << ":";
		 if(timer.tm_min < 10){
			 cout << "0" << timer.tm_min;
		 } else {
			 cout << timer.tm_min;
		 }
	while(!adtQue.empty()){

		if(timer.tm_hour == 13 && timer.tm_min == 12){
			temp.newPatient("Sam Sneezing", 50);
			adtQue.pop();
			adtQue.insert(temp);
			adtQue.insert(currentPatient);
			currentPatient = adtQue.top();
			cout << "\nLIFE THREAT: " << currentPatient.name << " at "
				 << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min;
				 } else {
					 cout << timer.tm_min;
				 }
			waitTimer = 0;
		}
		if(timer.tm_hour == 14 && timer.tm_min == 1){
			temp.newPatient("Sid Sickly", 50);
			adtQue.pop();
			adtQue.insert(temp);
			adtQue.insert(currentPatient);
			currentPatient = adtQue.top();
			cout << "\nLIFE THREAT: " << currentPatient.name << " at "
				 << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min;
				 } else {
					 cout << timer.tm_min;
				 }
			waitTimer = 0;
		}
		if(currentPatient.treatTime == 0){
			temp = adtQue.top();
			cout <<  " completed at " << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min << endl;
				 } else {
					 cout << timer.tm_min << endl;
				 }
			adtQue.pop();
			if(!adtQue.empty()){
			currentPatient = adtQue.top();

			cout << "Start: " << currentPatient.name << " at "
				 << timer.tm_hour << ":";
				 if(timer.tm_min < 10){
					 cout << "0" << timer.tm_min;
				 } else {
					 cout << timer.tm_min;
				 }
			}
			waitTimer = 0;
		}
		timer.tm_min++;
		waitTimer++;
		--currentPatient.treatTime;
		if(timer.tm_min == 60){
			timer.tm_min = 0;
			timer.tm_hour++;
		}
	}









	return 0;
}

