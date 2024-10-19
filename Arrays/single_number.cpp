// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

#include <iostream>
#include <map>
using namespace std;

int main() {
    
    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    map<int, int> mpp;

    for(int i = 0; i < n; i++){
        cout << "Enter the  element in the array " << i+1 << ": ";
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    for(auto it:  mpp){
        if(it.second == 1){
            cout << "The single element is: " << it.first;
            break;
        }
    }

    return 0;
}