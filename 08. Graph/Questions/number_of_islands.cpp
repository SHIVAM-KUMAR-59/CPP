/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// SC: O(n*m) and TC: O(n*m)

class Solution{
    private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid) {
       visited[row][col] = 1;
       queue<pair<int, int>> q;
       q.push({row, col});
       int n = grid.size();
       int m = grid[0].size();
       
       while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Traverse the neighbours and mark them if land
        for(int delRow = -1; delRow <= 1; delRow++){
            for(int delCol = -1; delCol <= 1; delCol++){
                int newRow = r + delRow;
                int newCol = c + delCol;
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
       }
    }
    public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, visited, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

