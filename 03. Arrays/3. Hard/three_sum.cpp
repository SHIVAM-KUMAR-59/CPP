// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <iostream>
#include <set>
#include <vector>
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

    // Brute Force: Take 3 pointers and iterate through the arrays
    // O(n^3)
    // set<vector<int> > st;
    // for(int i = 0; i < n; i++){
    //     for(int j =  i+1; j < n; j++){
    //         for(int k = j+1; k < n; k++){
    //             if(arr[i] + arr[j] + arr[k] == 0){
    //                 vector<int> temp = {arr[i], arr[j], arr[k]};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int> > ans(st.begin(), st.end());
    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Better Approach, using Hashing
    // O(n^2*longn)
    // set<vector<int> >st;
    // for(int i = 0; i < n; i++){
    //     set<int> hashSet;
    //     for(int j = i + 1; j < n; j++){
    //         int thirdElement = -(arr[i] + arr[j]);
    //         if(hashSet.find(thirdElement) != hashSet.end()){
    //             vector<int> temp = {arr[i], arr[j], thirdElement};
    //             sort(temp.begin(),  temp.end());
    //             st.insert(temp);
    //         }
    //         hashSet.insert(arr[j]);
    //     }
    // }
    // vector<vector<int> > ans(st.begin(), st.end());

    // Optimal Approach - Two Pointer
    // Fix the first element and then use two pointers 
    // If value is less than 0 then we have to increase the value
vector<vector<int>> ans;
        sort(arr, arr + n);  // Sort the input array
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;  // Skip duplicates for the first element
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0) {
                    j++;  // Move the left pointer to increase the sum
                } else if (sum > 0) {
                    k--;  // Move the right pointer to decrease the sum
                } else {
                    // Found a triplet
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    // Skip duplicates for the second element
                    while (j < k && arr[j] == arr[j - 1]) {
                        j++;
                    }
                    // Skip duplicates for the third element
                    while (j < k && arr[k] == arr[k + 1]) {
                        k--;
                    }
                }
            }
        }
    return 0;
}