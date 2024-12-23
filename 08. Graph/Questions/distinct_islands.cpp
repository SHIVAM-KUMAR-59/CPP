/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
*/

#include<iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
private:
    // Helper function for performing DFS and tracking the shape of the island
    void dfs(int row, int col, int row0, int col0, vector<vector<int>>& visited, vector<vector<int>>& grid, vector<pair<int, int>>& vec) {
        // Mark the current cell as visited
        visited[row][col] = 1;

        // Store the relative position of the cell to the origin (row0, col0)
        vec.push_back({row - row0, col - col0});

        // Define possible directions: up, left, down, right
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // Check if the new cell is within bounds, is part of the island (1), and is not yet visited
            if (newRow >= 0 && newRow < grid.size() &&
                newCol >= 0 && newCol < grid[0].size() &&
                grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                dfs(newRow, newCol, row0, col0, visited, grid, vec);
            }
        }
    }

public:
    // Function to count distinct islands
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        // Set to store unique shapes of islands
        set<vector<pair<int, int>>> uniqueIslands;

        // Visited matrix to track visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Traverse the entire grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is part of an unvisited island (grid[i][j] == 1)
                if (!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> shape;

                    // Perform DFS to explore the island and record its shape
                    dfs(i, j, i, j, visited, grid, shape);

                    // Insert the shape into the set of unique islands
                    uniqueIslands.insert(shape);
                }
            }
        }

        // The size of the set represents the number of distinct islands
        return uniqueIslands.size();
    }
};