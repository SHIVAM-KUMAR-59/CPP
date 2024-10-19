// Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k. Assuming all the elements are positive

#include <iostream>
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

    int a;
    cout  << "Enter the target sum: ";
    cin >> a;

    int longest_length = 0;
    // Brute Force - O(n^3)
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         int sum = 0;
    //         for(int k = i; k <= j; k++){
    //             sum += arr[k];
    //             if(sum == a){
    //                 longest_length = max(longest_length, j - i + 1);
    //             }
    //         }
    //     }
    // }
    // cout << "The length of the longest subarray with sum equal to " << a << " is " << longest_length << endl;

    // Better Approach - O(n^2)
    // for(int i = 0; i < n; i++){
    //     int sum = 0;
    //     for(int j = i; j < n; j++){
    //         sum +=  arr[j];
    //         if(sum == a){
    //             longest_length = max(longest_length, j - i + 1);
    //         }
    //     }
    // }
    // cout << "The length of the longest subarray with sum equal to " << a << " is " << longest_length << endl;

    // Another Better Approach, Hashing - TC -> O(nlogn) is using ordered map, O(n) for unordered map but in worset case, unorder map will give O(n^2)
    // This will be the optimal approach if the array has -ve, 0 and +ve numbers
    // map<long long int, int>preSumMap;
    // long long sum = 0;
    // int longest_length = 0;
    // for(int i = 0; i < n; i++){
    //     sum += arr[i];
    //     if(sum == a){
    //         longest_length = max(longest_length,  i + 1);
    //     }
    //     long long int rem = sum - a;
    //     if(preSumMap.find(rem) !=  preSumMap.end()){
    //         longest_length = max(longest_length, i - preSumMap[rem]);
    //     }
    //     if(preSumMap.find(sum) == preSumMap.end()){
    //         preSumMap[sum] = i;
    //     }
    // }
    // cout << "The length of the longest subarray with sum equal to " << a << " is " << longest_length << endl;

    // If the array has only +ve and 0 there can be another optimal solution:
    // Two Pointer Approach - O(n)
    int sum = arr[0];
    int longest_length = 0;
    int left = 0;
    int right = 0;
    while(right < n){
        while (left <= right && sum > a){
            sum -= arr[left];
            left++;
        }
        if(sum == a){
            longest_length = max(longest_length, right - left + 1);
        }
        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    cout << "The length of the longest subarray with sum equal to " << a << " is " << longest_length << endl;

    return 0;
}