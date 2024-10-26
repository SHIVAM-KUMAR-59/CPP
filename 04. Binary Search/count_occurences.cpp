// Count occurrences of a number in a sorted array with duplicates

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int lower_bound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n; // Default to n to indicate "not found" if the loop ends without assignment.
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upper_bound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n; // Default to n to indicate no greater element found.
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int countOccurrence(int arr[], int n, int target) {
    int firstPos = lower_bound(arr, n, target);
    if (firstPos == n || arr[firstPos] != target) {
        return 0; // Target not found
    }
    int lastPos = upper_bound(arr, n, target) - 1;
    return lastPos - firstPos + 1;
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    cout << "Count of " << target << " is " << countOccurrence(arr, n, target);
    return 0;
}
