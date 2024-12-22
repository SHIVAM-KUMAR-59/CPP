/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].
*/

#include <iostream>
#include <vector>
using namespace std;

// TC: O(N + 2E), SC: O(N)

class Solution {
private:
    // Function to detect a cycle in the graph using DFS
    bool detect(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1; // Mark the current node as visited

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            if (!visited[it]) {
                // If the adjacent node is not visited, do a recursive call
                if (detect(it, node, adj, visited)) {
                    return true;
                }
            } else if (it != parent) {
                // If the adjacent node is visited and not the parent, a cycle is detected
                return true;
            }
        }
        return false; // No cycle detected
    }

public:
    // Function to check whether the graph contains a cycle
    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();              // Number of vertices
        vector<int> visited(v, 0);       // Visited array initialized to 0

        // Check for cycles in all connected components of the graph
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {           // If the node is not visited
                if (detect(i, -1, adj, visited)) {
                    return true;         // Cycle detected
                }
            }
        }
        return false;                    // No cycle detected
    }
};
