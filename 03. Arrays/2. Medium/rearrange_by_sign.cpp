/* 
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

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

    // Brute Force Approach is we take 2 new arrays and store positive and negative arrays seperately and then modify the original array

    // Optimal Approach  is we use 2 pointers one for positive and one for negative and then we start filling the answer array with positive and negative elements
    
    int *ans = (int *)malloc(n * sizeof(int));
    int positive_index = 0;
    int negative_index = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            ans[negative_index] = arr[i];
            negative_index += 2;
        }else{
            ans[positive_index] = arr[i];
            positive_index += 2;
        }
    }

    return 0;
}