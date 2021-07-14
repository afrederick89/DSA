/*	Author: Alexander Frederick   *  PTR notation Extra Credit
 *  CS1C MW 1330-1620
 */


#include <string>
#include <iostream>

using namespace std;
int main()
{
	char *ptrarray[] = { "George",
	"Elliot's",
	"Oldest",
	"Girl",
	"Rode",
	"A",
	"Pig",
	"Home",
	"Yesterday",
	""
	};
	char **ptrptr = ptrarray;
	//OUTPUT - the d in rode
	cout << "ptrarray[4][2] or *(*(ptrptr+4)+2): "
		 << ptrarray[4][2] << " or " << *(*(ptrptr+4)+2);
	//OUTPUT - the last y in yesterday
	cout << "\nptrarray[8][8] or *(*(ptrptr+8)+8): "
		 << ptrarray[8][8] << " or " << *(*(ptrptr+8)+8);
	//OUTPUT - the H in home
	cout << "\nptrarray[7][0] or *(*(ptrptr+7)): "
		 << ptrarray[7][0] << " or " << *(*(ptrptr+7));
	//OUTPUT - the word Girl
	cout << "\nptrarray[3] or *(ptrptr + 3): "
		 << ptrarray[3] << " or " << *(ptrptr + 3);



	return 0;
}


