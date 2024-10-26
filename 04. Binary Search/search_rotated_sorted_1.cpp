/*
here is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
*/

#include <iostream>
using namespace std;

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int target = 0;
    int n = sizeof(nums)/sizeof(nums[0]);

    // Brute Force is Linear Searching
    // for(int i = 0; i < n; i++) {
    //     if(nums[i] == target) {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    // Optimal is Binary Search
    /*
    Approach:
    Identify the sorted half and search in that half
    */
   int left = 0;
   int right = n - 1;
   while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] >= nums[left]) {
        if (nums[left] <= target && target <= nums[mid]) {
            right = mid - 1;
        } else {
           left = mid + 1;
        }
    } else {
        if (nums[mid] <= target && target <= nums[right]) {
              left = mid + 1;
        } else {
              right = mid - 1;
        }
    }
}
    return 0;
}