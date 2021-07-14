//============================================================================
// Name        : Alex Frederick
// Assignment  : 10 - Directed DFS/BFS
// Date        : 4/16/2018
//============================================================================
/****************************************************************************
 * This file contains the functionality of the graph class and a comparator
 * to sort the edges by distance.
 *
 ****************************************************************************/

#include "graph.h"
struct edge_comp{
	inline bool operator()(const edge& first, const edge& second){
		return (first.dist < second.dist);
	}
};
int graph::addCity(string name){
	node temp;
	temp.name = name;
	cities.push_back(temp);
	return cities.size()-1;
}
void graph::addEdge(int o, int d, int dist){
	edge temp;
	temp.org = o;
	temp.dest = d;
	temp.dist = dist;
	adjList.push_back(temp);
	std::sort(adjList.begin(),adjList.end(),edge_comp());
}
int graph::DFSutil(int v, bool visited[]){
	int tempDist = 9999;
	int next;
	int prevShort;
	visited[v] = true;
	cout << "Visiting " << cities[v].name << '\n';
	for(int i = 0;i<adjList.size();++i){
		if(v == adjList[i].org){
			if(adjList[i].dist < tempDist){
				if(!visited[adjList[i].dest]){
				  next = adjList[i].dest;
				  tempDist = adjList[i].dist;
				  adjList[i].eType = "Discovery";
				} else {
					prevShort = adjList[i].dest;
				}
			}
		}
	}
	if(!visited[next]){
		totalDist += tempDist;
		return next;
	} else {
		cout << "Backtracking ";
		return prevShort;
	}

}
void graph::DFS(int s){
	totalDist = 0;
	visited = new bool[cities.size()];
	for(int i = 0;i<cities.size();++i){
		visited[i] = false;
	}
	for(int i = 0;i<cities.size()+1;++i){
	  s = DFSutil(s , visited);
	}
	cout << "Total Distance: " << totalDist;

}
void graph::BFS(int s){
	int tempDist;
	totalDist = 0;
	visited = new bool[cities.size()];
	for(int i = 0;i<cities.size();++i){
		visited[i] = false;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	s = queue.front();

	while(!queue.empty()) {
		s = queue.front();
		cout << "Visiting " << cities[s].name << '\n';
		queue.pop_front();
		for(int i = 0;i<adjList.size();++i){
			if(s == adjList[i].org){
				if(!visited[adjList[i].dest]){
					totalDist += adjList[i].dist;
					queue.push_back(adjList[i].dest);
					visited[adjList[i].dest] = true;
					adjList[i].eType = "Discovery";
				}

			}
		}
	}
	cout << "Total Distance: " << totalDist;
}
void graph::printEdges(){
	vector<edge>::iterator it;
	for(it = adjList.begin();it!=adjList.end();it++){
		cout << it->org << '\t' << it->dest << '\t' << it->dist
			 << '\t' << it->eType << '\n';
	}
	for(it = adjList.begin();it!=adjList.end();it++){
		it->eType = "Back";
	}
}
