// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  elements: " << i+1 << ": ";
        cin >> arr[i];
    }

    // Brute Force will be iterate through every subarray and calculate their sum and keep track of the maximum sum - O(n^3)

    // Better Solution is storing prefix sum - O(n^2)

    // Optimal Solution is Kadane's Algorithm - O(n)
    int max_sum = INT_MIN;
    int sum = 0;
    int start = -1, ans_start = -1, ans_end = -1;
    for(int i = 0; i < n; i++){

        if(sum == 0){
            start = i;
        }
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
            ans_start = start;
            ans_end = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }
    cout << "Maximum sum of subarray is: " << max_sum << endl;

    return 0;
}