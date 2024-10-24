// Given an integer array nums, find a subarray that has the largest product, and return the product.

#include <iostream>
using namespace std;

int main() {
    int nums[] = {2, 3, -2, 4};
    int n = sizeof(nums);

    // Brute force is to generate every subarray and  calculate the product and compare it
    // O(n^3)
    // int max_product = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         int product = 1;
    //         for(int k = i; k <= j; k++){
    //             product = product * nums[k];
    //         }
    //         max_product = max(max_product, product);
    //     }
    // }

    // Better Solution is to remove the third loop
    // O(n^2)
    // int max_product = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     int product = 1;
    //     for(int j = i; j < n; j++){
    //         product = product * nums[j];
    //         max_product = max(max_product, product);
    //     }
    // }

    // Optimal Approach:  O(n) 
    /*
    Approach: 
    If the array has all positive numbers then the maximum product will be the product of all the elements.
    If the array has even number negatives then again multiply every element.
    If the array has odd number of negatives then we need to remove 1 negative number so that we are left with even number of negatives.
    If the array has 0's divide the arrays into subarrays seperated by 0 and find the maximum product of subarrays.
    O(n)
    */
   int max_product = nums[0];
   int prefix = 1;
   int suffix = 1;
   for(int i = 0; i < n; i++){
    if(prefix == 0){
        prefix = 1;
    }
    if(suffix == 0){
        suffix = 1;
    }
    prefix *= nums[i];
    suffix *= nums[n - i - 1];
    max_product = max(max_product, max(prefix, suffix));
   }
    return 0;
}