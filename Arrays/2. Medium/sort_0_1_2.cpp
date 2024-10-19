// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

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

    int a;
    cout  << "Enter the a sum: ";
    cin >> a;  

    // Best Approach is Dutch National Flag Algorithm - O(n)
    /*
    There will be 3 variables: low, mid and high; the algorithm has 3 rules:
    1. Everything between 0 and low - 1 will be 0.
    2. Everything from low to mid - 1 should be 1.
    3. Everything from High + 1 to n - 1 should be 2.

    mid and low will start from 0th index, high will be at the last index
    Cases:
    1.  If arr[mid] is 0, then swap arr[mid] and arr[low] and increment both mid and low.
    2.  If arr[mid] is 1, then just increment mid.
    3.  If arr[mid] is 2, then swap arr[mid] and arr [high] and decrement high.
    */

   int low = 0;
   int mid = 0;
   int high = n - 1;
   for(int i = 0; i < n; i++){
      if(arr[mid] == 0){
        swap(arr[mid], arr[low]);
        mid++;
        low++;
      }else if(arr[mid] == 1){
        mid++;
      }else{
        swap(arr[mid], arr[high]);
        high--;
      }
   }

    cout << "Sorted Array: " << endl;
   for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
   }

    return 0;
}