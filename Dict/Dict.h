/*
 * Dict.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Alex
 */

#ifndef DICT_H_
#define DICT_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct dataNode{
	string value;
};
struct quadNode{
	int key;
	dataNode* data;
	quadNode* after;
	quadNode* before;
	quadNode* below;
	quadNode* above;
};

class Skip_list{
public:
	Skip_list ();
	~Skip_list();

	void print();
	quadNode* find(int searchKey);
	pair<quadNode*, quadNode*> findAll(int searchKey);
	quadNode* insert(int searchKey, string newVal);
	void erase(int searchKey);
	void erase(quadNode* searchKey);
	quadNode* begin();
	quadNode* end();
	int size();
	bool empty();

private:

	int randomGen();
	vector<quadNode*> height;
	vector<quadNode*> levels;
	int maxLevel;

	int minKey;
	int maxKey;
};



#endif /* DICT_H_ */
