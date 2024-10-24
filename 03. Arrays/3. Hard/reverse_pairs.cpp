/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
*/ 

#include <iostream>
using namespace std;

// Function to merge two halves of the array
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // Temporary array for merging
    int left = low;           // Starting index for the left sub-array
    int right = mid + 1;     // Starting index for the right sub-array
    int k = 0;               // Index for the temporary array

    // Merge the two halves into temp[]
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++]; // Take element from the left half
        } else {
            temp[k++] = arr[right++]; // Take element from the right half
        }
    }

    // Copy the remaining elements of the left half, if any
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // Copy the remaining elements of the right half, if any
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}

int countPairs(int arr[], int low, int mid, int high){
    int count = 0;
    int right = mid + 1;
    for(int i = low; i <= mid; i++){
        while(right <= high && arr[i]  > 2 * arr[right]){
            count +=  (high - right + 1);
        }
    }
    return count;
}

// Function to perform Merge Sort
int mergeSort(int arr[], int low, int high) {
    int count = 0;
    if (low < high) { // Ensure low < high
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);         // Sort the left half
        mergeSort(arr, mid + 1, high);    // Sort the right half
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);        // Merge the sorted halves
    }
    return count;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Brute Force is to generate all the pairs and check
    // O(n^2)
    // int count = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if(arr[i] > (2 * arr[j])){
    //             count++;
    //         }
    //     }
    // }

    // Optimal Solution: Merge Sort 
    int count = mergeSort(arr, 0, n - 1);
    cout << "Number of pairs: " << count << endl;
    return 0;
}