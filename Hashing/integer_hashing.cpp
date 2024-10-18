#include <iostream>
#include <vector> // Use vector for better memory management
#include <cstdlib> // For malloc and free
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the input array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        return 1; // Exit if memory allocation fails
    }

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Create a hash array to store frequency of elements
    // The size of the hash_array should be large enough to accommodate the max value in arr
    int maxValue = *max_element(arr, arr + n); // Find the maximum value in arr
    int *hash_array = (int *)calloc(maxValue + 1, sizeof(int)); // Create and zero-initialize the hash_array
    if (hash_array == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        free(arr); // Free the previously allocated memory
        return 1; // Exit if memory allocation fails
    }

    // Populate the hash_array with frequency counts
    for (int i = 0; i < n; i++) {
        hash_array[arr[i]] += 1; // Increment the count for each element
    }

    // Querying for counts
    while (true) {
        int a;
        cout << "Enter the number whose count you want to know (or enter -1 to exit): ";
        cin >> a;

        if (a == -1) {
            cout << "Exiting..." << endl;
            break; // Exit the loop
        }

        // Check if the queried number is within the valid range
        if (a >= 0 && a <= maxValue) {
            cout << "The count of " << a << " is: " << hash_array[a] << endl;

            if (hash_array[a] == 0) {
                cout << "The element is not present in the array." << endl;
            }
        } else {
            cout << "Invalid input! Please enter a number between 0 and " << maxValue << "." << endl;
        }
    }

    // Clean up allocated memory
    free(arr);
    free(hash_array);

    return 0;
}
