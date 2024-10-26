/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
*/

#include <iostream>
using namespace std;

int lower_bound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n; // Default to n to indicate "not found" if the loop ends without assignment.
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upper_bound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default to n to indicate no greater element found.
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8,  10};
    int target = 8;
    int n =  sizeof(nums)/sizeof(nums[0]);

    // Brute force is linear searching
    // int first = -1, last = -1;
    // for(int i = 0; i < n; i++){
    //     if(nums[i] == target){
    //         if(first == -1){
    //             first = i;
    //             last = i;
    //         }else{
    //             last = i;
    //         }
    //     }
    // }

    // Optimal is Binary Search
    /*
    Approach: Calculate the lower bound, it will give the first occurence if the element is present and then calculate upper bound, it will give the last occurence index + 1
    We must check if the value at lower bound is equal to the number we are searching for
    */
    int lowerBound = lower_bound(nums, n, target);
    if (lowerBound == n || nums[lowerBound] != target) {
        cout << "Range: [-1, -1]" << endl;
    } else {
        int upperBound = upper_bound(nums, n, target) - 1;
        cout << "Range: [" << lowerBound << ", " << upperBound << "]" << endl;
    }
    return 0;
}