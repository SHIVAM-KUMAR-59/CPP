
/*
Merge Sort:
Merge Sort is a divide-and-conquer algorithm that divides an array into two halves, recursively sorts them, and then merges the sorted halves. It has a time complexity of O(n log n).

Algorithm:
Divide: Split the array into two halves until each subarray contains one element.
Conquer: Recursively sort each half.
Combine: Merge the sorted halves to produce the sorted array.

Time Complexity:  O(nlogn)
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

// Function to perform Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) { // Ensure low < high
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);         // Sort the left half
        mergeSort(arr, mid + 1, high);    // Sort the right half
        merge(arr, low, mid, high);        // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Add a newline for better output formatting
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the mergeSort function
    mergeSort(arr, 0, n - 1);

    // Print the sorted array using the printArray function
    cout << "The sorted array is: ";
    printArray(arr, n);

    return 0;
}
