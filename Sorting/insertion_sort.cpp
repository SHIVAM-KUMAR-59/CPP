
/*
Insertion Sort: 
Iterate through the array and for every element put it at its correct position
Time Complexity:  O(n^2)
*/
#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // start from the second element
        int current = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than current to one position ahead
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;  // Place current at its correct position
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    // Call the insertionSort function
    insertionSort(arr, n);

    // Print the sorted array
    cout << "The sorted array is: ";
    printArray(arr, n);

    return 0;
}
