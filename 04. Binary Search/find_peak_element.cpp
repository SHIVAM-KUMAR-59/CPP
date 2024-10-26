
/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
*/
#include <iostream>
using namespace std;

int  findPeakElement(int nums[], int n) {
    if (n == 1) return 0;  // Only one element
    if (nums[0] > nums[1]) return 0;  // First element is peak
    if (nums[n - 1] > nums[n - 2]) return n - 1;  // Last element is peak
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid]  > nums[mid + 1] && nums[mid] > nums[mid - 1]){
            return mid;
        }
        else if(nums[mid] < nums[mid + 1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << findPeakElement(nums, n) << endl;
    return 0;
}