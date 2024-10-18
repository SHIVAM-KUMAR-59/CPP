#include <iostream>
#include <cstdlib>  // Include for malloc and free
using namespace std;

int main() {
    int n;  // Number of characters to be entered
    cout << "Enter the number of characters: ";
    cin >> n;

    // Dynamically allocate memory for character array
    char *arr = (char *)malloc(n * sizeof(char));
    if (arr == nullptr) {  // Check for successful memory allocation
        cerr << "Memory allocation failed!" << endl;
        return 1;  // Exit the program if allocation fails
    }

    // Prompt user to enter characters
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Store each character
    }

    // Create a hash array to store frequency of characters (a-z)
    char *frequency = (char *)malloc(26 * sizeof(char));
    if (frequency == nullptr) {  // Check for successful memory allocation
        cerr << "Memory allocation failed!" << endl;
        free(arr);  // Free previously allocated memory before exiting
        return 1;  // Exit the program if allocation fails
    }

    // Initialize the frequency array to zero
    for (int i = 0; i < 26; i++) {
        frequency[i] = 0;
    }

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        // Assuming input characters are lowercase letters
        frequency[arr[i] - 'a']++;  // Increment frequency for each character
    }

    // Query loop for user to find character frequencies
    while (true) {
        char a;  // Character to query
        cout << "Enter a character whose count you want to know or enter -1 to exit: ";
        cin >> a;

        if (a == -1) {
            cout << "Exiting.." << endl;
            break;  // Exit the loop if user inputs -1
        }

        // Check if the character is valid (a-z)
        if (a < 'a' || a > 'z') {
            cout << "Please enter a valid lowercase character (a-z)!" << endl;
            continue;  // Prompt again if input is invalid
        }

        // Check if the character was found
        if (frequency[a - 'a'] == 0) {
            cout << "Character not found!" << endl;
        } else if (frequency[a - 'a'] == 1) {
            // Print the frequency of the character
            cout << "The count of '" << a << "' is: " << (int)frequency[a - 'a'] << endl;
        }
    }

    // Free allocated memory
    free(arr);
    free(frequency);

    return 0;  // Indicate successful execution
}
