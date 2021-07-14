//============================================================================
// Name        : Alex Frederick
// Assignment  : 5 - Hash Map
// Date        : 3/7/2018
//============================================================================
/****************************************************************************
 * This File contains the template for the quadratic hashing algorithm.  The
 * template uses a vector bucket and a map to store the data.
 *
 ****************************************************************************/

#ifndef HASHMAPPTTWO_H_
#define HASHMAPPTTWO_H_

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <vector>
using namespace std;

template<class k, class v>
class HashMapPtTwo {
public:
	HashMapPtTwo(){Bucket.reserve(31);};
	int hash(int key, int j) {return ((key+(j*j)) % 31);};

	void put(k Key, v Value) {
		int temp;
		int count = 0;
		temp = hash(Key, count);
		map<int,string>::iterator t;
		if(Bucket[temp].second == false){
			Bucket[temp] = hashedMapt.insert(pair<int, string>(Key, Value));
		} else {
			while(Bucket[temp].second != false &&
				  count < 31){
				++count;
				temp = hash(Key, count);
			}
			if(Bucket[temp].second != false &&
				count < 31){
				Bucket[temp] = hashedMapt.insert(pair<int, string>(Key, Value));
			}
		}

	}
	map<int,string>::iterator find(k Key){
		int temp;
		int count = 0;
		map<int,string>::iterator t;
		temp = hash(Key, count);
		while(Bucket[temp].second != false &&
				count < 31 ){
			++count;
			temp = hash(Key, count);
			t = find(temp);
		}
		return t;
	}
	void erase(k Key){
		int temp;
		int count = 0;
		temp = hash(Key, count);
		if(Bucket[temp].second == true){
			hashedMapt.erase(Bucket[temp].first);
			Bucket[temp].second = false;

		} else {
			while(Bucket[temp].second != true &&
				  count < 31){
				++count;
				temp = hash(Key, count);
			}
			if(Bucket[temp].second != true &&
				count < 31){
				hashedMapt.erase(Bucket[temp].first);
				Bucket[temp].second = false;
			}
		}

	}
	void print(){
			map<int,string>::iterator it;
			vector<pair<map<int,string>::iterator,bool> >::iterator itt;
			for(it=hashedMapt.begin();it!=hashedMapt.end();it++){
				cout << "Key: " << it->first << " Value: " << it->second << '\n';
			}
	}

private:
	map<int,string> hashedMapt;
	vector<pair<map<int,string>::iterator,bool> > Bucket;

};





#endif /* HASHMAPPTTWO_H_ */
