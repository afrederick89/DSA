//============================================================================
// Name        : Alex Frederick
// Assignment  : 10 - Directed DFS/BFS
// Date        : 4/16/2018
//============================================================================
/****************************************************************************
 * This program has hard stored data for a directed graph data structure.
 * The program will perform a DFS then output the discovery/back edges for
 * that search.  Then it will perform a BFS and output the discovery/back
 * edges for that search.
 *
 ****************************************************************************/


#include "graph.h"

int main(){
	cout << "***************************************************************\n"
			"Name        : Alex Frederick\n"
			"Assignment  : 10 - DFS/BFS\n"
			"Date        : 4/16/2018\n"
			"***************************************************************\n";
	cout << "***************************************************************\n"
			"* This program has hard stored data for a directed graph \n"
			"* data structure. The program will perform a DFS then output \n"
			"* the discovery/back edges for that search.Then it will perform a \n"
			"* BFS and output the discovery/back edges for that search.\n"
			"***************************************************************\n";
	graph g;

	g.addCity("Seattle");//0
	g.addCity("San Francisco");//1
	g.addCity("Los Angeles");//2
	g.addCity("Denver");//3
	g.addCity("Chicago");//4
	g.addCity("Kansas City");//5
	g.addCity("Dallas");//6
	g.addCity("Houston");//7
	g.addCity("Atlanta");//8
	g.addCity("Miami");//9
	g.addCity("New York");//10
	g.addCity("Boston");//11

	g.addEdge(0,1,807);
	g.addEdge(0,3,1331);
	g.addEdge(1,2,381);
	g.addEdge(2,3,1015);
	g.addEdge(3,4,1003);
	g.addEdge(4,0,2097);
	g.addEdge(4,11,983);
	g.addEdge(5,2,1663);
	g.addEdge(5,3,599);
	g.addEdge(5,4,533);
	g.addEdge(5,8,864);
	g.addEdge(5,10,1260);
	g.addEdge(6,2,1435);
	g.addEdge(6,5,496);
	g.addEdge(6,8,781);
	g.addEdge(7,6,239);
	g.addEdge(7,8,810);
	g.addEdge(8,9,661);
	g.addEdge(9,7,1187);
	g.addEdge(10,8,888);
	g.addEdge(10,4,787);
	g.addEdge(11,10,214);
	cout << "DFS: \n";
	g.DFS(4);
	cout << "\nEdges: \n";
	g.printEdges();
	cout << "\nBFS: \n";
	g.BFS(4);
	cout << "\nEdges: \n";
	g.printEdges();

	cout << "\n\nPART C: This graph is strongly connected because it is\n"
			" possible for every node to reach the other nodes.\n";
	return 0;
}
