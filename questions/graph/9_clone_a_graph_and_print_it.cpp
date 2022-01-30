#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int src, dest, weight;
};

class Graph_Directed 
{
	public:
	vector<vector<pair<int, int>>> adjList;
	int n;

	Graph_Directed(int m) 
	{
		adjList.resize(m);;
		n = m;
	}

	void add_edges(int src, int dest, int weight);
};

void Graph_Directed::add_edges(int src, int dest, int weight)
{
	adjList[src].push_back(make_pair(dest, weight));	
}

void show_edges(vector<vector<pair<int, int>>> adjList)
{
	for(int i=0; i<adjList.size(); i++)
	{
		for (int j=0; j<adjList[i].size(); j++) 
		{
			auto item = adjList[i][j];	
			cout << i << item.first << item.second << endl;
		}
	}
}

vector<vector<pair<int, int>>> clone_graph(vector<vector<pair<int, int>>> adjList)
{
	vector<vector<pair<int, int>>> clone_adjList;

	int n = adjList.size();
	clone_adjList.resize(n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<adjList[i].size(); j++) 
		{
			auto item = adjList[i][j];	
			clone_adjList[i].push_back(make_pair(item.first, item.second));
		}
	}
	
	return clone_adjList;
}

int test1(void)
{
	Graph_Directed g(6);

	vector<Edge> edges = { 
		//src,dest,weight
		{0, 1, 6}, 
		{0, 5, 7}, 
		{1, 4, 5}, 
		{1, 2, 4}, 
		{2, 3, 8},
	  {3, 1, 1}, 
		{3, 0, 3},
		{4, 3, 4},
		{5, 4, 2}	
	};

	for(auto edge : edges)
		g.add_edges(edge.src, edge.dest, edge.weight);

	cout << endl;
	show_edges(g.adjList);


	vector<vector<pair<int, int>>> clone_adjList = clone_graph(g.adjList);
	cout << "Printing edges for clone graph" << endl;

	show_edges(clone_adjList);

	return 0;
}

int main(void)
{
	test1();
	return 0;
}
