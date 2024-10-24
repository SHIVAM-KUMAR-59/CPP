// Given an array arr of n integers, return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that:

#include <iostream>
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

    int target;
    cout << "Enter target sum: ";
    cin>>target;
     vector<vector<int>> ans;
        sort(arr, arr + n);  // Sort the input array
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;  // Skip duplicate for first element
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) {
                    continue;  // Skip duplicate for second element
                }
                int a = j + 1, b = n - 1;
                while (a < b) {
                    long long sum = static_cast<long long>(arr[i]) + arr[j] + arr[a] + arr[b];
                    if (sum < target) {
                        a++;  // Move the left pointer to increase the sum
                    } else if (sum > target) {
                        b--;  // Move the right pointer to decrease the sum
                    } else {
                        // Found a quadruplet
                        vector<int> temp = {arr[i], arr[j], arr[a], arr[b]};
                        ans.push_back(temp);
                        a++;
                        b--;

                        // Skip duplicates for the third element
                        while (a < b && arr[a] == arr[a - 1]) {
                            a++;
                        }
                        // Skip duplicates for the fourth element
                        while (a < b && arr[b] == arr[b + 1]) {
                            b--;
                        }
                    }
                }
            }
        }
    return 0;
}