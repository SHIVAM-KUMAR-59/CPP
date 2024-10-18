// Find the largest element in the array

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  element " << i+1 << ": ";
        cin >> arr[i];
    }

    int largest = arr[0];
    
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    cout << "The largest element is: " << largest << "." << endl;
}