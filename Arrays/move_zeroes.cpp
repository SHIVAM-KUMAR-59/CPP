// Move all the zeroes in an array to the left

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

    int i = 0;
    int j = 0;
    while(j < n){
        if(arr[j] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}