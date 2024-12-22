/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(N + 2E), SC: O(N)

class Solution {
private:
    // Helper function to detect a cycle using BFS
    bool detect(int src, vector<vector<int>>& adj, vector<int> &vis) {
        vis[src] = 1; // Mark the source as visited
        queue<pair<int, int>> q;
        q.push({src, -1}); // Push the source with parent as -1

        while (!q.empty()) {
            int node = q.front().first;  // Current node
            int parent = q.front().second; // Parent node
            q.pop();

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {
                if (vis[it] == 0) { // If the node is not visited
                    vis[it] = 1;   // Mark it as visited
                    q.push({it, node}); // Push it into the queue with current node as parent
                } else {
                    if (it != parent) { // If visited and not the parent, cycle detected
                        return true;
                    }
                }
            }
        }
        return false; // No cycle detected
    }

public:
    // Function to detect cycle in an undirected graph
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();  // Number of vertices
        vector<int> vis(V, 0);   // Visited array initialized to 0

        // Perform BFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) { // If the node is not visited
                if (detect(i, adj, vis)) { // If cycle is detected
                    return true;
                }
            }
        }
        return false; // No cycle detected in the graph
    }
};
