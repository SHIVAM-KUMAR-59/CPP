// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

#include <iostream>
using namespace std;

int search_index(int arr[], int n, int target){
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 3, 5, 6};
    int target = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << search_index(arr, n, target) << endl;
    return 0;
}