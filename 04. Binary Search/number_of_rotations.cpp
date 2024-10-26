// Find out how many times has an array been rotated

#include <iostream>
using namespace std;

int  findPeakElement(int nums[], int n) {
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid]  > nums[mid + 1] && nums[mid] > nums[mid - 1]){
            return mid;
        }
        else if(nums[mid] < nums[mid + 1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int peak = findPeakElement(arr, n);
    if(peak == n - 1){
        cout << "Array is not rotated" << endl;
    }else{
        cout << "Array is rotated " << peak + 1 << " times" << endl;
    }
    return 0;
}