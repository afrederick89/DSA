//============================================================================
// Name        : Alex Frederick
// Assignment  : 5 - Hash Map
// Date        : 3/7/2018
//============================================================================
/****************************************************************************
 * This File contains the template for the double hashing algorithm and the
 * structure of the data entries.
 *
 ****************************************************************************/

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Entry{
	int Key;
	string Value;
};
template<class k, class v>
class HashMap {
public:
	HashMap(){Bucket.reserve(29);};
	int hash(int key) {return key % 29;};
	int compress(int key) {return 17 - (key % 17);};
	void put(k Key, v Value) {
		int temp;
			temp = hash(Key);
			temp = compress(temp);
			Bucket[temp] = hashedMap.insert(pair<int, string>(Key, Value));

	}
	Entry* find(k Key){
		int temp = hash(Key);
		temp = compress(temp);
		return hashedMap.find(temp);
	}
	void erase(k Key){
		int temp = hash(Key);
		temp = compress(temp);
		hashedMap.erase(Bucket[temp].first);
	}
	void print(){
			map<int,string>::iterator it;
			for(it=hashedMap.begin();it!=hashedMap.end();it++){
				cout << "Key: " << it->first << " Value: " << it->second << '\n';
			}
		}
private:
	map<int,string> hashedMap;
	vector<pair<map<int,string>::iterator,bool> > Bucket;

};


#endif /* HASHMAP_H_ */
