/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
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

    /*
    1. Find the breakpoint from where there is a number on right of the breakpoint which is larger.
    2. Find the smallest greater number in the right side
    3. Swap the breakpoint with the smallest greater number
    4. Reverse the right side of the breakpoint
    5. If no breakpoint is found, reverse the array
    */ 
   int index = -1;
   for(int i = n - 2; i >= 0; i--){
    // Find breakpoint
    if(arr[i] < arr[i + 1]){
        index = i;
        break;
    }
   }

    // Index = -1 
   if(index == -1){
    // Reverse the array
    for(int i = 0; i < n / 2; i++){
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
   }else{
    // Find the smallest greater number
    for(int i = n - 1; i >= index; i--){
        if(arr[i] > arr[index]){
            int temp = arr[i];
            arr[i] = arr[index + 1];
            arr[index + 1] = temp;
            break;
        }
    }
    // Reverse the right side of the breakpoint
    for(int i = index + 1; i <  n / 2 + index; i++){
        int temp = arr[i];
        arr[i] = arr[n - i + index];
        arr[n - i + index] = temp;
    }
   }

    return 0;
}