/*
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the xor to find: ";
    cin >> k;

    // Brute force is to generate all the sub arrays and calculate their xor and match with the required xor
    // O(n^3)
    // int count = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         int res = 0;
    //         for(int k = i; k <= j; k++){
    //             res = arr[k] ^ res;
    //         }
    //         if(res == k){
    //             count++;
    //         }
    //     }
    // }

    // Better approach is to remove the third loop
    // O(n^2)
    // for(int i = 0; i < n; i++){
    //     int res = 0;
    //     for(int j = i; j < n; j++){
    //         res = res ^ arr[j];
    //         if(res == k){
    //             count++;
    //         }
    //     }
    // }

    // Optimal Solution is to use hashmap to store the xor of subarrays ending at i
    /*
    Approach:
    Imagine if the xor till a certain point is XR and subarray till that point has a xor of K then we can say that if the length till the certain point is x and the length of the subarray inside that subarray is y then there must exist a subarray with length x - y, let the xor of that subarray be Z then,
    K ^ Z must be equal to XR, i.e:
    K ^ Z = XR;
    Taking xor of K on both sides we get,
    (K ^ Z) ^ K = XR ^ K;
    Simplifying the above equation we get,
    Z = XR ^ K;
    */
   int count = 0;
   int xr = 0;
   map<int, int> mpp;
   mpp[xr]++;

   for(int i = 0; i < n; i++){
    xr = xr ^ arr[i];
    count += mpp[xr ^ k];
    mpp[xr]++;
   }

    // Deallocate memory
    delete[] arr;
    
    return 0;
}
