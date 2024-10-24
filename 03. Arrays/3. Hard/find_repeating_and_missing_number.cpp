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

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    int missing = -1, repeating = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] != i + 1){
            missing = i + 1;
        }
    }

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            repeating = arr[i];
        }
    }

    cout << "The missing numder is: " << missing << endl;
    cout << "The repeating numder is: " << repeating;



    return 0;
}