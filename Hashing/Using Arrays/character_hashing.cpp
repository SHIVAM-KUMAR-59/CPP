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

    // Create a hash array to store frequency of characters (0-255)
    int *frequency = (int *)malloc(256 * sizeof(int));
    if (frequency == nullptr) {  // Check for successful memory allocation
        cerr << "Memory allocation failed!" << endl;
        free(arr);  // Free previously allocated memory before exiting
        return 1;  // Exit the program if allocation fails
    }

    // Initialize the frequency array to zero
    for (int i = 0; i < 256; i++) {
        frequency[i] = 0;
    }

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        frequency[(unsigned char)arr[i]]++;  // Increment frequency for each character
    }

    // Query loop for user to find character frequencies
    while (true) {
        char a;  // Character to query
        cout << "Enter a character whose count you want to know or enter 'exit' to exit: ";
        cin >> a;

        if (a == 'exit') {
            cout << "Exiting.." << endl;
            break;  // Exit the loop if user inputs "exit"
        }

        // Check if the character was found and print frequency
        if(frequency[a]){
            cout << "The count of '" << a << "' is: " << frequency[(unsigned char)a] << endl;
        }else{
            cout << "The entered character '" << a << "' was not found." << endl;
        }
        
    }

    // Free allocated memory
    free(arr);
    free(frequency);

    return 0;  // Indicate successful execution
}
