/*
Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
  private:
   vector<int> topologicalSort(int n, vector<int> adj[]) {
        vector<int> visited(n, 0);
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> ans;
        
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
            ans.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        int n = dict.size();
        vector<int> adj[k];
        vector<int> indegree(k, 0);
        for(int i = 0; i < n - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topologicalSort(k, adj);
        string res = "";
        for(auto it:topo){
            res += (char)(it + 'a');
        }

        return res;

    }
};