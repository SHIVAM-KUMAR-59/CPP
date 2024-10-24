// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int arr[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << "Enter the element: ";
            cin >>  arr[i][j];
        }
    }

    // Brute Force: Iterate through the matrix, and for each element, check if it's 0. If it is, set the entire row and column as -1 then iterate again and set all the -1 to 0.
    // O(n^3) almost
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(arr[i][j] == 0){
    //             for(int k = 0; k < n; k++){
    //                 if(arr[k][j] != 0){
    //                     arr[k][j] = -1;
    //                 }
    //             }
    //             for(int k = 0; k < m; k++){
    //                 if(arr[i][k] != 0){
    //                     arr[i][k] = -1;
    //                 }
    //             }
    //         }
    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(arr[i][j] == -1){
    //             arr[i][j] = 0;
    //         }
    //     }
    // }

    // cout << "The Modified Matrix: "<< endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Better Solution Approach: For any 1 to be 0 in the final matrix, if there exists minimum of 1 zero in either the respective row or column and keep a track.
    // O(n^2) SC: O(n) + O(m)
    // int col_track[m]; // To track column index
    // int row_track[n]; // To track row index
    // for(int i = 0; i < m; i++){
    //     col_track[i] = 0;
    // }
    // for(int i = 0; i < n; i++){
    //     row_track[i] = 0;
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(arr[i][j] == 0){
    //             row_track[i] = 1;
    //             col_track[j] = 1;
    //         }
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(arr[i][j] == 1 && (row_track[i] == 1 ||  col_track[j] == 1)){
    //             arr[i][j] = 0;
    //         }
    //     }
    // }

    // Optimal Solution:
    int col0 = 1; // Track if the first column needs to be set to 0

        // Step 1: Traverse the matrix and mark the first row and first column
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) col0 = 0; // Mark if the first column needs to be zero
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0; // Mark the first element of the row
                arr[0][j] = 0; // Mark the first element of the column
            }
        }
    }

    // Step 2: Use the marks to set other elements to zero
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    // Step 3: Set the first row to zero if needed
    if (arr[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }

     // Step 4: Set the first column to zero if needed
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
             arr[i][0] = 0;
        }
    }

    cout << "The Modified Matrix: "<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}