//============================================================================
// Name        : Alex Frederick
// Assignment  : 10 - Directed DFS/BFS
// Date        : 4/16/2018
//============================================================================
/****************************************************************************
 * This file contains the header for the Graph class, its nodes, and edges.
 *
 ****************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct node{
	string name;
};
struct edge{
	int org;
	int dest;
	int dist;
	string eType = "Back";
};

class graph{
public:
	graph() {};
	~graph() {};
	int addCity(string name);
	void addEdge(int o, int d, int dist);
	void DFS(int s);
	void BFS(int s);
	int DFSutil(int v, bool visited[]);
	void printEdges();
private:
	vector<node> cities;
	vector<edge> adjList;
	bool *visited;
	int totalDist;
};


