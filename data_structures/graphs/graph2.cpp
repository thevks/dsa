// DFS algorithm in C++

#include <iostream>
//#include <list>
#include <vector>
using namespace std;

class Graph {
  int numVertices;
  //list<int> *adjLists;
  vector<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  //adjLists = new list<int>[vertices];
  adjLists = new vector<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  //adjLists[src].push_front(dest);
  adjLists[src].push_back(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  //list<int> adjList = adjLists[vertex];
  vector<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  //list<int>::iterator i;
  vector<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(2);

  return 0;
}