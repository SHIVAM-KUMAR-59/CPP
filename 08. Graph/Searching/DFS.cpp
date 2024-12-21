// DFS, Depth First Search or Level Wise Traversal, it uses Stack data structure

/*
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    int v = adj.size(); // Number of vertices
    vector<int> visited(v, 0); // Visited array initialized to 0
    vector<int> dfs; // To store DFS traversal
    stack<int> s;

    visited[0] = 1; // Mark the first node as visited
    s.push(0); // Start DFS from node 0

    while (!s.empty()) {
        int node = s.top(); // Access the top element of the stack
        s.pop(); // Remove the top element
        
        dfs.push_back(node); // Add the current node to DFS result

        // Add all unvisited neighbors to the stack (in reverse order for correct DFS)
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
            if (!visited[*it]) {
                visited[*it] = 1; // Mark as visited
                s.push(*it); // Push the adjacent node
            }
        }
    }

    return dfs; // Return the DFS traversal
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},   // Edges for node 0
        {0, 3},   // Edges for node 1
        {0, 3},   // Edges for node 2
        {1, 2}    // Edges for node 3
    };

    vector<int> result = dfsOfGraph(adj);
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
