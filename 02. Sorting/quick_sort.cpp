
/*
How Quick Sort Works:
Choose a Pivot:
A pivot element is selected from the array. The choice of the pivot can vary (commonly, it's the last element, the first element, or a random element).
Partitioning:
The array is rearranged (partitioned) so that all elements less than the pivot are moved to its left, and all elements greater than the pivot are moved to its right.
After partitioning, the pivot is in its final sorted position.
Recursion:
The process is recursively applied to the sub-arrays formed by partitioning. The sub-arrays to the left and right of the pivot are sorted independently.
Base Case:
The recursion ends when the sub-array has one or no elements, as they are inherently sorted.

*/
#include <iostream>
using namespace std;

// Function to swap two elements in the array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to arrange elements based on pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than the pivot
            i++;               // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot element to its correct position
    return i + 1; // Return the partition index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);       // Recursively sort elements before partition
        quickSort(arr, pi + 1, high);      // Recursively sort elements after partition
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

    // Call the quickSort function
    quickSort(arr, 0, n - 1);

    // Print the sorted array using the printArray function
    cout << "The sorted array is: ";
    printArray(arr, n);

    return 0;
}
