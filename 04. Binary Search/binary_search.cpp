// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// O(logn)

#include <iostream>
using namespace std;

int binary_search(int arr[], int target, int n) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Recalculate mid inside the loop

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] > target) {
            right = mid - 1; // Move to the left half
        } else {
            left = mid + 1; // Move to the right half
        }
    }
    return -1; // Target not found
}

int recursive_binary_search(int arr[], int target, int n, int low, int high){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return recursive_binary_search(arr, target, n, low, mid - 1);
    }else{
        return recursive_binary_search(arr, target, n, mid + 1, high);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = binary_search(nums, target, n);
    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}
