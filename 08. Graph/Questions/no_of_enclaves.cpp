/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)

class Solution{
    
    public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Mark all the corner 1's
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newX = x + delRow[i];
                int newY = y + delCol[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && visited[newX][newY] == 0){
                    q.push({newX, newY});
                    visited[newX][newY] = 1;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};