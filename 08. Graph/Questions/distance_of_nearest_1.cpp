/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(n*m)
// SC: O(n*m)

class Solution{
    public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Store all initial ones in the queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }else{
                    visited[i][j] = 0;
                }
            }
        }

        // Adjacent cells
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
 
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[x][y] = d;

            // Explore all adjacent cells
            for(int i = 0; i < 4; i++){
                int newX = x + delRow[i];
                int newY = y + delCol[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] == 0){
                    visited[newX][newY] = 1;
                    q.push({{newX, newY}, d + 1});
                }
            }
        }

        return dist;
    }
};