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
	void bfs();
	void dfs();
	void dfs_util(int i, vector<bool> &visited);

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

void Graph_Directed::bfs()
{
	vector<bool> visited(adjList.size(), false);
	queue<int> q;

	q.push(0);	//starting from 0th node
	visited[0] = true;

	while(!q.empty())
	{
		int i = q.front();
		cout << i << endl;
		
		for (auto item : adjList[i])
			if(!visited[item.first]) {
				visited[item.first] = true;
				q.push(item.first);
			}
		
		q.pop();
	}

	cout << "Printing visited array " << endl;
	for (int i=0; i<adjList.size(); i++)
		cout << visited[i];

	cout << endl;

	return;
}

void Graph_Directed::dfs_util(int i, vector<bool> &visited)
{
	visited[i] = true;
	cout << i << " ";

	for(auto item: adjList[i])
		if (!visited[item.first])
			dfs_util(item.first, visited);
}

void Graph_Directed::dfs()
{
	vector<bool> visited(n, false);
	
	for (int i=0; i<n; i++)
		if (!visited[i])
			dfs_util(i, visited);
}


int main(void)
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
	{
		//cout << edge.src << edge.dest << edge.weight << endl;
		g.add_edges(edge.src, edge.dest, edge.weight);
	}

	cout << endl;

	g.show_edges();

	cout << "DFS Traversal" << endl;
	g.bfs();
	cout << endl;

	cout << "DFS Traversal" << endl;
	g.dfs();
	cout << endl;

	return 0;
}
