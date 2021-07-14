/* Client.h    Author: Alexander Frederick
 * Class: CS1C MW 1330-1620
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

namespace globalvar {
	const double tax_rate = 0.0775;
};
struct product {
	string p_name;
	double cost;
	int quantity;
};

void PrintInventory(product *inv, int limit) {
	int i = 0;
	int col1 = 25;
	int col2 = 8;
	cout << "Current Inventory: \n";
	cout << setw(col1) << left << "Product" << "  |  "
		 << setw(col2) << "Cost" << "  |  "
		 << setw(col1) <<"Quantity" << '\n';
	while(i < limit) {
		cout << setw(col1) << inv[i].p_name << "  |  "
			 << setw(col2)  << inv[i].cost << "  |  "
			 << setw(col1) <<inv[i].quantity << '\n';
		++i;
	}
	cout << right;
};
void PrintPurchase(product *inv, int max) {
	int col1 = 25;
	int col2 = 8;
	double pretax = 0.0;
	double posttax = 0.0;

	cout << "\n\nReceipt for Purchase\n";
	cout << setw(col1) << left << "Product" << "  |  "
		 << setw(col2) << "Cost" << "  |  "
		 << setw(col1) <<"Quantity" << '\n';
	cout << setw(col1) << inv[0].p_name << "  |  "
		 << setw(col2) << inv[0].cost << "  |  "
		 << setw(col1) << 4 << '\n';
	pretax += (4 * inv[0].cost);
	inv[0].quantity -= 4;
	cout << setw(col1) << inv[1].p_name << "  |  "
		 << setw(col2) << inv[1].cost << "  |  "
		 << setw(col1) << 3 << '\n';
	pretax += (3 * inv[1].cost);
	inv[1].quantity -= 3;
	cout << setw(col1) << inv[3].p_name << "  |  "
		 << setw(col2) << inv[3].cost << "  |  "
		 << setw(col1) << 1 << '\n';
	pretax += (1 * inv[3].cost);
	inv[3].quantity -= 1;
	cout << setw(col1) << inv[4].p_name << "  |  "
		 << setw(col2) << inv[4].cost << "  |  "
		 << setw(col1) << 4 << '\n';
	pretax += (4 * inv[4].cost);
	inv[4].quantity -= 4;
	posttax = pretax + (pretax * globalvar::tax_rate);
	cout << setprecision(2) << fixed;
	cout << "\nPretax: $" << pretax
		 << " | Total Tax: $" << pretax * globalvar::tax_rate
		 << " | Total Cost: $" << posttax << '\n';
}

#endif /* CLIENT_H_ */
