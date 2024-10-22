#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    int a;
    cout << "Enter the target sum: ";
    cin >> a;

    // Brute force approach: generate all subarrays and check the sum
    // O(n^2) almost
    // int count = 0;
    // for (int i = 0; i < n; i++) {
    //     int sum = 0;
    //     for (int j = i; j < n; j++) {
    //         sum += arr[j];
    //         if (sum == a) {
    //             count++;
    //         }
    //     }
    // }
    // cout << "Total number of subarrays with sum " << a << " is: " << count << endl;
    // free(arr);

    // Optimal Approach -  Prefix Sum Approach - Lets assume that the sum of numbers uptil an index is x and a subarray inside that range have the required sum k then there must exist a prefix subarray with the sum (x - k) which is also present in the range 
    // O(n) time complexity
    int prefix_sum = 0;
    int count = 0;
    map<int, int> mpp;
    mpp[0] = 1; // sum 0 is present at index 0
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        int remainder = prefix_sum - a;
        count += mpp[remainder];
        mpp[prefix_sum] += 1;
    }

    return 0;
}
