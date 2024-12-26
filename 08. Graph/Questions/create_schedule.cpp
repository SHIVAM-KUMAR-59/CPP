/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of P prerequisite pairs, find if it is possible to finish all tasks.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
         int n = prerequisites.size();

         vector<int> adj[n];
         for(auto it:prerequisites){
            adj[it.first].push_back(it.second);
         }

        vector<int> indegree(n, 0);
        queue<int> q;
        int count = 0;
        
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

        return count == n;
    }
}