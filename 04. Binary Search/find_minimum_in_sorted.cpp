/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
*/

#include <iostream>
using namespace std;

int findMin(int nums[], int n){
    int low = 0;
    int high = n - 1;

    // If the array is not rotated, return the first element
    if (nums[low] <= nums[high]) {
        return nums[low];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the minimum element
        if (mid > 0 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }
        if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        // Decide whether to search left or right
        if (nums[mid] >= nums[low]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // This should never be reached if the array is valid
}


int main() {
    int nums[] = {4,5,6,7,8,0,1,2,3};
    int n = sizeof(nums)/sizeof(nums[0]);
    int ans = findMin(nums, n);
    cout << ans;
    return 0;
}