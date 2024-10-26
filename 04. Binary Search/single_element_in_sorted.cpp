#include <iostream>
using namespace std;

int singleNumber(int nums[], int n) {
    int low = 0;
    int high = n - 1;
    
    // Handle boundary case if single element is at the start or end
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if `mid` is the single element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        
        // Determine the pattern side: if mid is even and pairs on the left or mid is odd and pairs on the right
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1; // This should not be reached for a valid input
}

int main() {
    int arr[] = {0, 1, 1, 2, 2, 4, 4, 5, 5, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Single element is: " << singleNumber(arr, n) << endl;
    return 0;
}
