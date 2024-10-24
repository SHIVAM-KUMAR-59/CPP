
/*
Insertion Sort: 
Iterate through the array and for every element put it at its correct position
Time Complexity:  O(n^2)
*/
#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        int j = i;
        while(j >= 0 && arr[j - 1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    cout << "The sorted array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}