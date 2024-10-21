// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    
    while(left <= right && top <= bottom) {
    // Right to Left
    for(int i = left; i <= right; i++){
        cout << arr[top][i] << " ";
    }
    top++;

    // Top to Bottom
    for(int i = top; i <= bottom; i++){
        cout << arr[i][right] << " ";
    }
    right--;

    // Right to Left
    if(top  <= bottom){
    for(int i = right; i >= left; i--){
        cout << arr[bottom][i] << " ";
    }
    bottom--;
    }

    // Bottom to Top
    if(left <= right){
    for(int i = bottom; i >= top; i--){
        cout << arr[i][left] << " ";
    }
    left++;
    }
    }
    return 0;
}