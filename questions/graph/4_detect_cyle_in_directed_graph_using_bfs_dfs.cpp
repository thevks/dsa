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
	void show_edges();
	bool dfs_util(int src, vector<bool> &visited, vector<bool> &order);
	bool is_cyclic();

};

void Graph_Directed::add_edges(int src, int dest, int weight)
{
	adjList[src].push_back(make_pair(dest, weight));	
}

void Graph_Directed::show_edges()
{
	for(int i=0; i < adjList.size(); i++)
	{
		for (int j=0; j< adjList[i].size(); j++) 
		{
			auto item = adjList[i][j];	
			cout << i << item.first << item.second << endl;
		}
	}
}

bool Graph_Directed::dfs_util(int src, vector<bool> &visited, vector<bool> &order)
{
	visited[src] = true;
	order[src] = true;

	cout << src << " ";

	for(auto item: adjList[src]) {
		if (!visited[item.first]) { 
			if (dfs_util(item.first, visited, order) == true)
				return true;	
		}
		else if(order[item.first]) return true;
	}

	order[src] = false;
	return false; 
}

bool Graph_Directed::is_cyclic()
{
	vector<bool> visited(n, false);
	vector<bool> order(n, false);
	
	for (int i=0; i<n; i++)
		if (!visited[i])
			if (dfs_util(i, visited, order) == true)
				return true;

	return false;
}


int test2(void)
{
	Graph_Directed g(4);
	vector<Edge> edges = { 
		{0, 1, 0},
		{0, 2, 0},
		{1, 2, 0},
		{2, 0, 0},
		{2, 3, 0},
		{3, 3, 0}
	};

	for(auto edge: edges)
		g.add_edges(edge.src, edge.dest, edge.weight);

	if(g.is_cyclic())
		cout << "The graph contains cycle " << endl;
	else
		cout << "The graph does not contain cycle " << endl;

	return 0;		
}

int main(void)
{
	test2();
	return 0;
}
