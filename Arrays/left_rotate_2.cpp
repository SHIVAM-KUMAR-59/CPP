// Left Rotate an array by k places

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  element in ascending order " << i+1 << ": ";
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of places you want to rotate: ";
    cin >> k;

    // Brute Force -  Time Complexity: O(n + rotation) Space Complexity: O(rotation)
    // int rotation = k % n;
    // int temp[rotation];
    // for(int i = 0; i < rotation; i++){
    //     temp[i] = arr[i];
    // }
    // for(int i = rotation; i < n; i++){
    //     arr[i - rotation] = arr[i];
    // }
    // for(int i = n - rotation; i < n; i++){
    //     arr[i] = temp[i - (n - rotation)];
    // }

    // Optimal Approach - reverse the first k elements, reverse the rest of the array, and reverse the whole array
    // Time Complexity: O(n) Space Complexity: O(1)
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);


    cout << "Rotated Array: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}