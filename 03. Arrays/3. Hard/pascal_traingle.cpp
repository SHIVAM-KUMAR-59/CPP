// Given an integer numRows, return the first numRows of Pascal's triangle. In Pascal's triangle, each number is the sum of the two numbers directly above it.

/*
Given row and column number, find the element at that position in pascal's triangle
Formula for that is:  C(n - 1, k - 1) = n! / (k! * (n-k)!)
// O(row) SC: O(n)
int  element(int row, int col){
    res = 1;
    for(int i = 0; i < row; i++){
        res = res  * (col - i);
        res = res / (i + 1);
    }
    return res;
}
*/ 

/*
Given a number n, print the nth row:
Brute force can be to run a loop and call the function that gives the element
O(n * r)

for(int col = 1; col < n; col++){
    cout << element(n - 1, col - 1);
}

But we can do better than that. We can use the fact that each row is a prefix of  the next row So we can just use the previous row to generate the next row
O(n) SC: O(r)

int ans = 1;
cout << ans;
for(int i = 1; i < n; i++){
    ans = ans * (n - i);
    ans = ans / i;
    cout << ans;
}
*/

#include <iostream>
using namespace std;

// Functiont to generate a row: O(n)
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int i = 1; i < row; i++){
        ans = ans * (row - i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    // Brute Force can be using the function to generate the element
    // O(n^3)
    // vector<int> ans;
    // for(int row = 1; row < numRows; row++){
    //     vector<int> temp;
    //     for(int col = 1; col <= row; col++){
    //         temp.push_back(element(row - 1, col - 1));
    //     }
    //     ans.push_back(temp);
    // }

    // Optimal Solution is to use the previous row to generate the next row
    vector<vector<int> > ans;
    for(int i = 1; i <= numRows; i++){
        vector<int> temp = generateRow(i);
        ans.push_back(temp);
    }

    return 0;
}