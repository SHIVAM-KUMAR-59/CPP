// You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

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

    // Brute Force will be to search for each element in the array and check if it is a leader or not
    // Optimal:
    vector<int> ans;
    int maximum = INT_MIN;
    for(int i = n - 1; i >=0 ; i--){
        if(arr[i] >= maximum){
            ans.push_back(arr[i]);
        }
        maximum = max(maximum, arr[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}