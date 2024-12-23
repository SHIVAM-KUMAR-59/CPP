/*
Given a matrix mat where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)

class Solution{
    private:
     void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& mat){
        
        visited[row][col] = 1;

        // Check for all four directions
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            // Check if within bounds
            if(newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size() && mat[newRow][newCol] == 'O' && !visited[newRow][newCol]){
                dfs(newRow, newCol, visited, mat); // Recursive DFS Call
            }
        }
     }
    public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Traverse the first row and column and last row and column

        // Traverse First row and last row
        for(int i = 0; i < m; i++){
            // First row
            if(!visited[0][i] && mat[0][i] == 'O' ){
                dfs(0,i, visited, mat);
            }
            // Last row
            if(!visited[n-1][i] && mat[n-1][i] == 'O' ){
                dfs(n-1, i, visited, mat);
            }

        }

        // Travers First and Last column
        for(int i = 0; i < n; i++){
            // First column
            if(!visited[i][0] && mat[i][0] == 'O' ){
                dfs(i, 0, visited, mat);
            }
            // Last column
            if(!visited[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, visited, mat);
            }
        }

        // Convert the O's into X
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};