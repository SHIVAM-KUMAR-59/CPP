/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Enter size of first array: ";
    cin >> n;
    int nums1[n];
    cout << "Enter elements of first array: ";
    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }

    int m;
    cout << "Enter size of second array: ";
    cin >> m;
    int nums2[m];
    cout << "Enter elements of second array: ";
    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }

    // Brute Force is to take a third array and insert elements from both arrays
    // O(n + m) SC: O(n + m)
    // int nums3[n+m];
    // int left = 0, right = 0, index = 0;
    // while(left  < n && right < m){
    //     if(nums1[left] <= nums2[right]){
    //         nums3[index] = nums1[left];
    //         left++;
    //         index++;
    //     }
    //     else{
    //         nums3[index] = nums2[right];
    //         right++;
    //         index++;
    //     }
    // }

    // while(left < n){
    //     nums3[index++] = nums1[left++];
    // }
    // while(right < m){
    //     nums3[index++] = nums2[right++];
    // }

    // for(int i = 0; i < n + m; i++){
    //     if(i < n){
    //         nums1[i] = nums3[i];
    //     }else{
    //         nums2[i - n] = nums3[i];
    //     }
    // }

    // Better Solution can be to compare the largest and the smallest element and put them in their correct place
    // O(min(n + m)) SC: O(1)
    int left = n - 1, right = 0;
    while(left >= 0 && right < m){
        if(nums1[left] > nums2[right]){
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(nums1, nums1 + n);
    sort(nums2, nums2 + m);

    return 0;
}