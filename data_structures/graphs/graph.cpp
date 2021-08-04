// Adjascency List representation in C++
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

/*
// Print the graph
void printGraph(vector<int> adj[], int n) {
  for (int d = 0; d < n; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}
*/

void printGraph(vector<int> adj[]) {
  int n = adj->size();
  for (int d = 0; d < n; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  int n = 5;
  // Create a graph
  vector<int> adj[n];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  
  //printGraph(adj, n);
  printGraph(adj);
}