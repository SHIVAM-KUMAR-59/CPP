/*
Given a matrix where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i, j] can rot other fresh orange at indexes [i-1, j], [i+1, j], [i, j-1], [i,j+1] (up, down, left and right) in unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();           // Number of rows
        int m = mat[0].size();        // Number of columns

        // Queue to store {{row, col}, time} for BFS
        queue<pair<pair<int, int>, int>> q;

        // Visited matrix to track visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Initialize the queue with all rotten oranges and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) { // Rotten orange
                    q.push({{i, j}, 0}); // Push with time = 0
                    visited[i][j] = 2;   // Mark as visited
                } else {
                    visited[i][j] = 0;   // Mark as unvisited
                }
            }
        }

        int time = 0; // To store the maximum time required

        // Direction arrays for 4 neighbors: up, right, down, left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;  // Current row
            int c = q.front().first.second; // Current column
            int t = q.front().second;       // Time taken so far
            time = max(time, t);            // Update the maximum time
            q.pop();

            // Check all 4 neighboring cells
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];       // Neighbor's row
                int nc = c + dcol[i];       // Neighbor's column

                // Valid neighbor check
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    visited[nr][nc] != 2 && mat[nr][nc] == 1) {
                    mat[nr][nc] = 2;        // Mark as rotten
                    visited[nr][nc] = 2;    // Mark as visited
                    q.push({{nr, nc}, t + 1}); // Push with incremented time
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) { // Fresh orange found
                    return -1;        // Not all oranges can be rotten
                }
            }
        }

        return time; // Return the time required to rot all oranges
    }
};
