/*
Given an adjacency list of a graph adj. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    private:
    bool dfs(int start, int color, vector<vector<int>>& adj, vector<int>& visited){
        visited[start] = color;
        for(int i : adj[start]){
            if(visited[i] == -1){
                if(!dfs(i, 1 - color, adj, visited)){
                    return false;
                }
            }
            else if(visited[i] == color){
                return false;
            }
        }
        return true;
    }
    public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, adj, color)){
                    return false;
                }
            }
        }
        return true;
    }
};