// Lower bound is thes mallest index such that arr[index] >= x

#include <iostream>
using namespace std;

int lower_bound(int arr[], int n, int target){
    int low = 0, high = n - 1;
    int ans = -1;
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
    
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << lower_bound(nums, n, target);
    return 0;
}