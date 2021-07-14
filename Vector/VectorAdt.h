/*
 * VectorAdt.h
 *
 *  Created on: Feb 14, 2018
 *      Author: Alex
 */

#ifndef VECTORADT_H_
#define VECTORADT_H_

#include <iostream>
#include <string>
using namespace std;

template <class Type> class ArrayVector {
  public:
    ArrayVector();					// constructor
    ~ArrayVector();
    int size() const;				// number of elements
    bool empty() const;				// is vector empty?
    Type& operator[](int i);		// element at index
    Type& at(int i); 				// element at index
    void erase(int i);				// remove element at index
    void insert(int i, const Type& e);	// insert element at index
    void reserve(int N);			// reserve at least N spots
				              	  	// assignment operator
    void printV();
  private:
    int capacity;			// current array size
    int n;					// number of elements in vector
    Type* A;				// array storing the elements
  };
template <class Type>
  ArrayVector<Type>::ArrayVector()
  : capacity(0), n(0), A(NULL) { }

template <class Type>
ArrayVector<Type>::~ArrayVector(){
	delete A;
}
template <class Type>
int ArrayVector<Type>::size() const
	{ return n; }

template <class Type>
bool ArrayVector<Type>::empty() const
  { return size() == 0; }

template <class Type>
Type& ArrayVector<Type>::operator[](int i)
  { return A[i]; }

template <class Type>   					// element at index (safe)
Type& ArrayVector<Type>::at(int i) {
  if (i < 0 || i >= n){
	cout << "Index out of bounds!\n";
  } else {
	cout << "At position:[" << i << "] : " << A[i] << '\n';
	  return A[i];
  }
}
template <class Type>
void ArrayVector<Type>::erase(int i) {
	if(!this->empty() && i<this->size()){
		cout << "Erasing " << A[i] << " at position [" << i << "]\n";
		for (int j = i+1; j < n; j++)
		  A[j - 1] = A[j];
		n--;
	} else {
		cout << "Invalid Erase!\n";
	}
  }
template <class Type>
void ArrayVector<Type>::reserve(int N) {
	if (capacity >= N) return;			// already big enough
	Type* B = new Type[N];				// allocate bigger array
	for (int j = 0; j < n; j++)			// copy contents to new array
		B[j] = A[j];    if (A != NULL) delete [] A; // discard old array
	A = B;								// make B the new array
	capacity = N;						// set new capacity
	cout << "Reserved " << N << " capacity.\n";
 }
template <class Type>
void ArrayVector<Type>::insert(int i, const Type& e) {
	if (n >= capacity)						// overflow?
	  reserve(max(1, 2 * capacity));		// double array size
	for (int j = n - 1; j >= i; j--)		// shift elements up
	  A[j+1] = A[j];
	A[i] = e;								// put in empty slot
	cout << "Inserting " << e << " at position [" << i << "]\n";
	n++;									// one more element
  }
template <class Type>
void ArrayVector<Type>::printV(){
	for(int i=0;i<this->size();++i){
		cout << "Position:[" << i << "]: "<< A[i] << '\n';
	}
}



#endif /* VECTORADT_H_ */
