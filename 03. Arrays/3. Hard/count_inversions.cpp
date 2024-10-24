
// Give the number of pairs in which the left element is greater than the right element
#include <iostream>
using namespace std;

int pairCount = 0; // Declare pairCount globally

// Function to merge two halves of the array
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // Temporary array for merging
    int left = low;           // Starting index for the left sub-array
    int right = mid + 1;     // Starting index for the right sub-array
    int k = 0;                // Index for the temporary array

    // Merge the two halves into temp[]
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++]; // Take element from the left half
        } else {
            // Count the pairs: all remaining elements in left sub-array
            // are greater than the current element in the right sub-array
            pairCount += (mid - left + 1);
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

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform merge sort
    mergeSort(arr, 0, n - 1);
    
    // Output the count of pairs
    cout << "Number of pairs where left element is greater than right element: " << pairCount << endl;  

    // Clean up the dynamically allocated memory
    delete[] arr;

    return 0;
}
