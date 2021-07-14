//============================================================================
// Name        : Alex Frederick
// Assignment  : 4 - Binary Tree
// Date        : 2/14/2018
//============================================================================
/****************************************************************************
 * This Program implements a Binary tree, prints the tree in a readable format
 * and outputs the values of the in-order, post order, pre order, and breadth
 * traversals.
 *
 ****************************************************************************/
#include "BTree.h"

int main() {
	int data[] = {109, 55, 118, 89, 33, 1001, 18, 44, 88, 12, 24, 49, 7, 25,
				  59, 28, 19, 13, 888};
    BST<int> *bst = new BST<int>();
    for(int i=0;i<19;++i){
    	bst->add(data[i]);
    }
	cout << "***************************************************************\n"
			"Name        : Alex Frederick\n"
			"Assignment  : 4 - Binary Tree\n"
			"Date        : 2/21/2018\n"
			"***************************************************************\n";
	cout << "***************************************************************\n"
			"* This Program implements a Binary tree, prints the tree in a\n"
			"* readable format and outputs the values of the in-order, post\n"
			"* order, pre order, and breadth traversals.\n"
			"***************************************************************\n";
	cout << "Current Data: ";
    bst->print();
    cout<<endl;
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    bst->printTree();
    cout << "Post Order: ";
    bst->printPost();
    cout << endl;
    cout << "Pre Order: ";
    bst->printPre();
    cout << endl;
    cout << "In Order: ";
    bst->printInOrd();
    cout << endl;
    cout << "Breadth Order: ";
    bst->printBreadth();
    return 0;
}
