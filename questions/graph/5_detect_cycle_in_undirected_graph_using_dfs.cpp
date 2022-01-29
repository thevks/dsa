#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int src; 
	int dest;
};

class Graph_Un_Directed	//No weight on edge 
{
	public:
	vector<vector<int>> adjList;
	int n;

	Graph_Un_Directed(int m) 
	{
		adjList.resize(m);;
		n = m;
	}

	void add_edges(int src, int dest);
	bool dfs_util(int src, vector<bool> &visited, int par);
	bool is_cyclic();

};

void Graph_Un_Directed::add_edges(int src, int dest)
{
	adjList[src].push_back(dest);	
	adjList[dest].push_back(src);	
}


bool Graph_Un_Directed::dfs_util(int src, vector<bool> &visited, int par)
{
	visited[src] = true;

	cout << src << " ";

	for(auto x: adjList[src]) {
		if (!visited[x]) { 
			if (dfs_util(x, visited, src)) return true;	
		}
		else if(x != par) return true;
	}

	return false; 
}

bool Graph_Un_Directed::is_cyclic()
{
	vector<bool> visited(n, false);
	vector<bool> order(n, false);
	
	for (int i=0; i<n; i++)
		if (!visited[i])
			if (dfs_util(i, visited, -1)) return true;

	return false;
}


int test2(void)
{
	Graph_Un_Directed g(5);
	vector<Edge> edges = { 
		{0, 1},
		{1, 2},
		{1, 4},
		{2, 3},
		{4, 3}
	};

	for(auto edge: edges)
		g.add_edges(edge.src, edge.dest);

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
