// Find the minimum and maximum frequency

#include <iostream>
#include <map>
#include <cstdlib> // Include for malloc and free
#include <limits>  // Include for INT16_MAX

using namespace std;

int main() {
    // Declare the size of the array
    int n;
    cout << "Enter the size of your array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == nullptr) {  // Check for successful memory allocation
        cerr << "Memory allocation failed!" << endl;
        return 1;  // Exit if allocation fails
    }

    // Input elements into the array and count their frequencies
    map<int, int> mpp; // Map to store each element and its frequency
    for (int i = 0; i < n; i++) {
        cout << "Enter the element at position " << i + 1 << ": ";
        cin >> arr[i];
        mpp[arr[i]]++;  // Increment the count for each element
    }

    // Initialize variables to find max and min frequencies
    int max_frequency = 0;
    int min_frequency = INT16_MAX; // Use INT16_MAX as a large initial value
    int max_value; // To store the value with the highest frequency
    int min_value; // To store the value with the lowest frequency

    // Iterate through the map to find the elements with max and min frequencies
    for (auto it : mpp) {
        if (it.second > max_frequency) {
            max_frequency = it.second; // Update max frequency
            max_value = it.first; // Update value with max frequency
        }
        if (it.second < min_frequency) {
            min_frequency = it.second; // Update min frequency
            min_value = it.first; // Update value with min frequency
        }
    }

    // Output the elements with the highest and lowest frequency
    cout << "The element with the highest frequency is: " << max_value << " (Frequency: " << max_frequency << ")" << endl;
    cout << "The element with the lowest frequency is: " << min_value << " (Frequency: " << min_frequency << ")" << endl;

    // Free allocated memory
    free(arr);

    return 0;  // Indicate successful execution
}
