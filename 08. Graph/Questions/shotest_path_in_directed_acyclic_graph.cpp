/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
 private:
    void dfs(int node, vector<int>& visited, vector<pair<int, int>> adj[], stack<int>& s) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!visited[v]) {
                dfs(v, visited, adj, s);
            }
        }
        s.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Perform topological sort
        vector<int> visited(V, 0);
        stack<int> s;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, s);
            }
        }

        // Initialize distance vector
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Assuming 0 is the source node

        // Relax edges in topological order
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (dist[node] != INT_MAX) { // Process only if node is reachable
                for (auto it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }

        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
