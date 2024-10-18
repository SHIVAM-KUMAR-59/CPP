// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include <iostream>
#include <map>
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
    
    int totalSum = 0;
    int arraySum = 0;
    for(int i = 1; i < n; i++){
        totalSum += i;
    }
    for(int i = 0; i <  n; i++){
        arraySum += arr[i];
    }

    cout <<  "Missing number is: " << totalSum - arraySum << endl;
    return 0;
}