// Given an array of integers arr and an integer a, return indices of the two numbers such that they add up to a.

#include <iostream>
#include <map>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  elements: " << i+1 << ": ";
        cin >> arr[i];
    }

    int a;
    cout  << "Enter the a sum: ";
    cin >> a;   

    // Brute Force - O(n^2)
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         if(i == j){
    //             continue;
    //         }
    //         if(arr[i] + arr[j] == a){
    //             cout << "Indices of the two numbers are: " << i << " and " << j;
    //             break;
    //         }
    //     }
    // }

    // Another Brute Force Solution but still very close to O(n^2)
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if(arr[i] + arr[j] == a){
    //             cout << "Indices of the two numbers are: " << i << " and " << j;
    //         }
    //     }
    // }

    // Better Approach using Hashing - O(nlogn) for ordered map
    // map<int, int> mpp;
    //    for(int i = 0; i < n; i++){
    //     int number = arr[i];
    //     int difference = a - number;
    //     if(mpp.find(difference) != mpp.end()){
    //         cout <<  "Indices of the two numbers are: " << mpp[difference] << " and " <<  i;
    //     }
    //     mpp[number] = i;
    //    }

    // Optimal Approach - 2 Pointer
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == a){
            cout << "Indices of the two numbers are: " << left << " and " << right
            << endl;
            break;
        }
        else if(sum < a){
            left++;
        }
        else{
            right--;
        }
    }
    return 0;
}