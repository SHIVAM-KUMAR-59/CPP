/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the new color.
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        // If the newColor is the same as the oldColor, no need to process
        if (oldColor == newColor) return image;

        // Directions for 4 neighbors: left, right, top, bottom
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor; // Mark the starting pixel with the new color

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Traverse all 4 neighbors
            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check boundaries and if the neighbor has the old color
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == oldColor) {
                    q.push({nx, ny});
                    image[nx][ny] = newColor; // Mark it with the new color
                }
            }
        }

        return image;
    }
};