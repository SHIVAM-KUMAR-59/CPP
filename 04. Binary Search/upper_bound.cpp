// Upper bound is thes mallest index such that arr[index] > x

#include <iostream>
using namespace std;

int upper_bound(int arr[], int n, int x){
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5,  6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    int index = upper_bound(arr, n, x);
    if(index != -1){
        cout << "Upper bound of " << x << " is " << index << endl;
    }
    else{
        cout << x << " is not present in the array" << endl;
    }
    return 0;
}