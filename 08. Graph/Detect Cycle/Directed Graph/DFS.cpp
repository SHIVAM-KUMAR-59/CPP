/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.
 */

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int>& visited, vector<int> &pathVisited){

        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, pathVisited)){
                    return true;
                }
            }else{
                if(pathVisited[it]){
                    return true;
                }
            }
        }

        pathVisited[node] = 0;
        return false;
    }
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited)){
                    return true;
                }
            }
        }
        return false;
    }
};