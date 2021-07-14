/* Client.h    Author: Alexander Frederick
 * Class: CS1C MW 1330-1620
 */
#include "Client.h"

int main() {
	product* myInv = NULL;
	int max = 10;
	int n = 0;
	ifstream fin;
	fin.open("Inventory.txt");
	myInv = new product [max];
	while (fin) {
		getline(fin, myInv[n].p_name);
		fin >> myInv[n].cost;
		fin.ignore(1000, '\n');
		fin >> myInv[n].quantity;
		fin.ignore(1000, '\n');
		++n;
		if (n >= max) {
			max = max * 2;
		    product* temp = new product[max];
		    for (int i=0; i<n; i++) {
		    	temp[i].p_name = myInv[i].p_name;
		        temp[i].cost = myInv[i].cost;
		        temp[i].quantity = myInv[i].quantity;
		    }
		    delete [] myInv;
		    myInv = temp;
		}
	}
	fin.close();

	PrintInventory(myInv, n);
	PrintPurchase(myInv, n);
	cout << '\n';
	PrintInventory(myInv, n);
	delete [] myInv;
	return 0;
}

