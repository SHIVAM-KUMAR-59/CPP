#include <iostream>
#include <map>
using namespace std;

int main() {
    // Declare the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == nullptr) {  // Check for successful memory allocation
        cerr << "Memory allocation failed!" << endl;
        return 1;  // Exit if allocation fails
    }

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Create a map to store the frequency of each element
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;  // Increment the count for each element
    }

    // Iterating in the map
    // for(auto it : mpp) {
    //     cout << it.first << " " << it.second << endl;
    // }

    // Input number of queries
    int query;
    cout << "Enter the number of queries: ";
    cin >> query;

    // Process each query
    while (query--) {
        int number;
        cout << "Enter the number to query its frequency: ";
        cin >> number;

        // Output the frequency of the queried number
        cout << "The count of " << number << " is: " << mpp[number] << endl;
    }

    // Free allocated memory
    free(arr);

    return 0;  // Indicate successful execution
}
