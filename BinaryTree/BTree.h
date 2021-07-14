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
#ifndef BTREE_H_
#define BTREE_H_



#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
struct Node {
    T value;
    Node *left;
    Node *right;

    Node(T val) {
        this->value = val;
        left = NULL;
        right = NULL;
    }

    Node(T val, Node<T> left, Node<T> right) {
        this->value = val;
        this->left = left;
        this->right = right;
    }
};

template <class T>
class BST {
private:
Node<T> *root;

void addHelper(Node<T> *root, T val) {
	if (root->value > val) {
		if (!root->left) {
			root->left = new Node<T>(val);
		} else {
			addHelper(root->left, val);
		}
	} else {
		if (!root->right) {
			root->right = new Node<T>(val);
		} else {
			addHelper(root->right, val);
		}
	}
}

void printHelper(Node<T> *root) {
	if (!root) return;
	printHelper(root->left);
	cout<<root->value<<' ';
	printHelper(root->right);
}

int nodesCountHelper(Node<T> *root) {
	if (!root) return 0;
	else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
}

int heightHelper(Node<T> *root) {
	if (!root) return 0;
	else return 1 + max(heightHelper(root->left), heightHelper(root->right));
}

void printMaxPathHelper(Node<T> *root) {
	if (!root) return;
	cout<<root->value<<' ';
	if (heightHelper(root->left) > heightHelper(root->right)) {
		printMaxPathHelper(root->left);
	} else {
		printMaxPathHelper(root->right);
	}
}

bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
	if (!current) return false;
	if (current->value == value) {
		if (current->left == NULL || current->right == NULL) {
			Node<T>* temp = current->left;
			if (current->right) temp = current->right;
			if (parent) {
				if (parent->left == current) {
					parent->left = temp;
				} else {
					parent->right = temp;
				}
			} else {
				this->root = temp;
			}
		} else {
			Node<T>* validSubs = current->right;
			while (validSubs->left) {
				validSubs = validSubs->left;
			}
			T temp = current->value;
			current->value = validSubs->value;
			validSubs->value = temp;
			return deleteValueHelper(current, current->right, temp);
		}
		delete current;
		return true;
	}
	return deleteValueHelper(current, current->left, value) ||
		   deleteValueHelper(current, current->right, value);
}

public:
	void add(T val) {
		if (root) {
			this->addHelper(root, val);
		} else {
			root = new Node<T>(val);
		}
	}

	void print() {
		printHelper(this->root);
	}

	int nodesCount() {
		return nodesCountHelper(root);
	}

	int height() {
		return heightHelper(this->root);
	}

	void printMaxPath() {
		printMaxPathHelper(this->root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(NULL, this->root, value);
	}

	BST(){
		root = NULL;
	}
	void printPost(){
		postorder(this->root, 1);
	}
	void printInOrd(){
		inOrder(this->root, 1);
	}
	void printBreadth(){
		vector<int> temp;
		breadthOrder(this->root, temp);
	}
	void printPre(){
		preorder(this->root, 1);

	}
	void printTree(){
		tree(this->root, this->height());
	}
	void tree(Node<T>* p, int indent = 0){
		int h = height() * 2;
		      for (int i = 0; i<h;i++) {
		         printRow(p, h, i);
		      }
	}
	void printRow(const Node<T>* p, const int height, int depth)
	{
	        vector<int> vec;
	        string space = " ";
	        getLine(p, depth, vec);
	        for(int i=0;i<depth;++i){
	        	space += " ";
	        }
	        cout << setw((height-depth)*2); // scale setw with depth
	        bool toggle = true; // start with left
	        if (vec.size() > 1) {
	                for (int v=0;v<vec.size();++v) {
	                	if(vec[v] != 0){
							if (toggle){
								cout << "/" << "   ";
							} else {
								cout << "\\" << "   ";
							}
	                	} else {
							cout << "    ";
	                	}
	                        toggle = !toggle;

	                }
	                cout << endl;
	                cout << setw((height - depth)*2);
	        }
	        for (int v=0;v<vec.size();++v) {
	        if(vec[v] != 0){
	        	cout << vec[v] << "   ";
	        } else {
	        	cout << "    ";
	        }
	        }
	        cout << endl;
	}
	void getLine(const Node<T> *root, int depth, vector<int>& vals)
	{
	        if (depth <= 0 && root != NULL) {
	                vals.push_back(root->value);
	                return;
	        }
	        if (root->left != NULL)
	                getLine(root->left, depth-1, vals);
	        else if (depth-1 <= 0)
	                vals.push_back(0);
	        if (root->right != NULL)
	                getLine(root->right, depth-1, vals);
	        else if (depth-1 <= 0)
	                vals.push_back(0);
	}


	void postorder(Node<T>* p, int indent=0){
		 if(p != NULL) {
			if(p->left != NULL) {
				postorder(p->left, indent+4);
			}
			if(p->right != NULL) {
				postorder(p->right, indent+4);
			}
			cout<< p->value << " ";

		  }

	}
	void preorder(Node<T>* p, int indent=0){
		 if(p != NULL) {
			 cout << p->value << " ";
				if(p->left != NULL) {
					preorder(p->left, indent+4);
				}
				if(p->right != NULL){
					preorder(p->right, indent+4);
				}
		}
	}
	void inOrder(Node<T>* p, int indent=0){
			 if(p != NULL) {
				if(p->left != NULL){
					inOrder(p->left);
				}
				cout << p->value << " ";
				if(p->right != NULL){
					inOrder(p->right);
				}

			}
		}
	void breadthOrder(Node<T>* p, vector<int> temp){
		int h = height() * 2;
		for (int i = 0; i<h;i++) {
			printBre(p, h, i);
		}
	}
	void printBre(const Node<T>* p, const int height, int depth)
	{
	        vector<int> vec;
	        getLine(p, depth, vec);

	        for (int v=0;v<vec.size();++v) {
	        	if(vec[v] != 0){
				cout << vec[v] << " ";
	        	}

	        }
	}
};


#endif /* BTREE_H_ */
