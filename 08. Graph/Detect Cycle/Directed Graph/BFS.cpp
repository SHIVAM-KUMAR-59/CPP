/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.
 */

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> indegree(n, 0);
        queue<int> q;
        int count = 0;;
        
        for(int i = 0; i < n; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        count == n ? true : false;
    }
};