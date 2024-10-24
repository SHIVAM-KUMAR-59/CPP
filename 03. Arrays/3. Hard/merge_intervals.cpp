// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <iostream>
using namespace std;

int main() {
    int arr[][2] = {{1,3},{2,6},{8,10},{15, 18}};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Brute Force Club the closer intervals together or sort the pairs and then search
    // O(nlogn) + O(2n)
    // sort(arr, arr + n);
    // vector<vector<int> >ans;
    // for(int i = 0; i < n; i++){
    //     int start = arr[i][0];
    //     int end = arr[i][1];
    //     if(!ans.empty() && end <= ans.back()[1]){
    //         continue;
    //     }
    //     for(int j = i + 1; j < n; j++){
    //         if(arr[j][0] <=  end){
    //             end = max(end, arr[j][1]);
    //         }else{
    //             break;
    //         }
    //     }
    //     ans.push_back({start, end});
    // }

    // Optimal Approach
    sort(arr, arr + n);
    vector<vector<int> >ans;
    for(int i = 0; i < n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return 0;
}