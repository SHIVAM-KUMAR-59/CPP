// Find the second largest element in the array

#include <iostream>
#include <set>
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
    int second_largest = INT32_MIN;

    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
    }

    cout << "The second largest element is: " << second_largest << "." << endl;
    return 0;
}