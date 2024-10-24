/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Enter rows and columns: ";
    cin >> n;

    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Enter the element: ";
            cin >>  arr[i][j];
        }
    }

    // Brute Force - Create another answer amtrix and traverse through the original matrix and place every element correctly in the answer matrix
    // O(n^2), O(n^2)
    // int answer[n][n];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         answer[j][n - i - 1] = arr[i][j];
    //     }
    // }

    // Transpose the matrix and then reverse every row
    // O(N/2 * N/2) + O(N * N/2) = O(n^2)
     for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = arr[i][n - j - 1];
        }
    }

    return 0;
}