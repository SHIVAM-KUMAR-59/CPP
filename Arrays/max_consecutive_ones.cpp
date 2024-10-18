// Given a binary array nums, return the maximum number of consecutive 1's in the array.

#include <iostream>
using namespace std;

int main() {
        
    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  element in binary format " << i+1 << ": ";
        cin >> arr[i];
    }

    int count = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
            max = max > count ? max : count;
        }else{
            count = 0;
        }
    }

    cout <<  "Maximum number of consecutive 1's: " << max << endl;
    return 0;
}