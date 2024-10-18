// Left Rotate an array by 1 place

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

    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    cout << "Rotated Array: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}