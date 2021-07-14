/* Author : Alexander Frederick Team B.A.C.O.N. Feature: CSV Converter
 * Feature converts the sales files into a csv type format for db read in
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
	int counter = 1;
	ifstream fin;
	ofstream fout;
	char buffer[100];
	string date, product;
	int memNum, quantity;
	float cost;
	fin.open("day6.txt");
	fout.open("day6csv.bin", ios::out | ios::binary);
	cout << "Open\n";
	while(fin){
		getline(fin, date);
		fin >> memNum;
		fout.write((char*)&memNum, sizeof(int));
		fin.ignore(10000, '\n');
		getline(fin, product);
		fin >> cost;
		fout.write((char*)&cost, sizeof(float));
		fin.ignore(100, '\t');
		fin >> quantity;
		fout.write((char*)&quantity, sizeof(int));
		fin.ignore(10000, '\n');
		cout << counter << "Evaluated\n";
		cout << counter << "Output\n";
		++counter;
	}
	fin.close();
	fout.close();

}
