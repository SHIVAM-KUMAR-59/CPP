// BFS, Breadth First Search or Level Wise Traversal, it uses Queue data structure
/*
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    int v = adj.size(); // Number of vertices
    vector<int> visited(v, 0); // Visited array initialized to 0
    vector<int> bfs; // To store BFS traversal
    queue<int> q;

    visited[0] = 1; // Mark the first node as visited
    q.push(0); // Start BFS from node 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node); // Add the current node to BFS result

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1; // Mark as visited
                q.push(it); // Push the adjacent node
            }
        }
    }

    return bfs; // Return the BFS traversal
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},   // Edges for node 0
        {0, 3},   // Edges for node 1
        {0, 3},   // Edges for node 2
        {1, 2}    // Edges for node 3
    };

    vector<int> result = bfsOfGraph(adj);
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
