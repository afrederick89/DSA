/* Author: Alexander Frederick * Singleton
 * Due: 12 December 2017        * CS1C MW 1330-1620
 */

#include "iostream"

#include "Singleton.h"

using namespace std;

int main() {
	string jobs;
	PrintQueueSingleton *pQue;
	PrintQueueSingleton *secondQue;
	pQue = PrintQueueSingleton::instance();
	jobs = "Job 1";
	pQue->AddJob(jobs);
	jobs = "Job 2";
	pQue->AddJob(jobs);
	pQue->CancelJob(3);
	pQue->CancelJob(1);
	pQue->CancelJob();
	pQue->CancelJob();
	pQue->CancelJob();
	secondQue = PrintQueueSingleton::instance();
	secondQue->CancelJob();

	return 0;
}



