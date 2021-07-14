/* Author: Alexander Frederick * Singleton
 * Due: 12 December 2017        * CS1C MW 1330-1620
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_
#define MAX_SIZE 10
#include <vector>
#include <iostream>

using namespace std;


class PrintQueueSingleton{
public:
	~PrintQueueSingleton();
	static PrintQueueSingleton* instance();
	int AddJob(string sTextToPrint);
	void CancelJob(int nJobNumber = 0);
private:
	PrintQueueSingleton();
	vector<string> requests;
	static PrintQueueSingleton* thisQue;
	int jobCount;
	static bool instanceFlag;
};

class InvalidRequest{
};
#endif /* SINGLETON_H_ */
