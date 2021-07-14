/*
 * Dict.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Alex
 */

#include "Dict.h"

Skip_list::Skip_list(){
	minKey = -100;
	maxKey = 100;
	size = 0;
}
quadNode* Skip_list::begin(){
	return levels.front();
}
quadNode* Skip_list::end(){
	return levels.back();
}
quadNode* Skip_list::find(int searchKey){

}


//class Skip_list{

//public:
//	void print();
//quadNode* find(int searchKey);
//pair<quadNode*, quadNode*> findAll(int searchKey);
//quadNode* insert(int searchKey, string newVal);
//void erase(int searchKey);
//void erase(quadNode* searchKey);
//quadNode* begin();
//quadNode* end();
//int size();
//bool empty();
//private:
//
//	int randomGen();
//	vector<quadNode*> levels;
//	int maxLevel;
//
//	int minKey;
//	int maxKey;
//};


