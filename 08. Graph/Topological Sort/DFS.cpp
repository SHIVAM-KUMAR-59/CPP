/*
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    private:
    void dfs(int node, vector<int> &visited, vector<vector<int>>& adj, stack<int> &s){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, visited, adj, s);
            }
        }
        s.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        stack<int> s;
        
        // Perform DFS on all vertices
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, adj, s);
            }
        }

        vector<int> ans;
        // Pop elements from the stack and add them to the result vector
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();  // Important: Pop the element from the stack
        }

        return ans;
    }

};