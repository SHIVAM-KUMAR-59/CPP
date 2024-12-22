/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// SC: O(N) + O(N)
// TC: O(N) + O(V + 2E) 

class Solution {
  private:
    void dfs(int node, vector<int> adjList[], int visited[]) {
        visited[node] = 1; // Mark the node as visited
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(it, adjList, visited); // Recursively visit unvisited neighbors
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Convert adjacency matrix to adjacency list
        vector<int> adjList[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        // Initialize visited array
        int visited[V];
        memset(visited, 0, sizeof(visited));

        // Count connected components
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                count++; // Increment the province count
            }
        }

        return count;
    }
};