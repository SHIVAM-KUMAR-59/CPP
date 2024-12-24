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
    public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        int m = adj[0].size();
        vector<int> color(n, -1);
        queue<int> q;

        q.push(0);
        color[0] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it] == -1){ // If node not colored then color it with a different color
                    color[it] = !color[node];
                    q.push(it);
                }else{ // If node is already colored and it has the same color as the current node then it's not bipartite graph
                    if(color[it] == color[node]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};