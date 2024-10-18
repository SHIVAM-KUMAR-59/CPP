#include <iostream>
#include <map>
#include <cstdlib> // Include for malloc and free

using namespace std;

int main() {
    // Declare the number of characters
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    // Dynamically allocate memory for the character array
    char *arr = (char *)malloc(n * sizeof(char));
    if (arr == nullptr) {  // Check for successful memory allocation
        cerr << "Memory allocation failed!" << endl;
        return 1;  // Exit if allocation fails
    }

    // Input characters into the array
    for (int i = 0; i < n; i++) {
        cout << "Enter the character at index " << i + 1 << ": ";
        cin >> arr[i];  // Store each character
    }

    // Create a map to store the frequency of each character
    map<char, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;  // Increment the count for each character
    }

    // Optional: Display the frequency map
    cout << "Character frequencies:" << endl;
    for (auto it : mpp) {
        cout << it.first << ": " << it.second << endl; // Print each character and its frequency
    }

    // Input the number of queries
    int query;
    cout << "Enter the number of queries: ";
    cin >> query;

    // Process each query
    while (query--) {
        char a;
        cout << "Enter the character to be searched: ";
        cin >> a;

        // Output the frequency of the queried character
        cout << "The count of '" << a << "' is: " << mpp[a] << endl;
    }

    // Free allocated memory
    free(arr);

    return 0;  // Indicate successful execution
}
