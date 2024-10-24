// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

#include <iostream>
#include <set>
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

    // Brute Force - Take an element say x, check if x + 1, x + 2.. is present or not and keep record of the max length
    // O(n^2)
    // int max_len = 1;
    // for(int i = 0; i < n; i++){
    //     int x = arr[i];
    //     int curr_len = 1;
    //     while(i + 1 < n && arr[i + 1] == x + 1){
    //         i++;
    //         curr_len++;
    //     }
    //     max_len = max(max_len, curr_len);
    // }
    // cout << "Length of the longest consecutive elements sequence is: " << max_len << endl;

    // Better Solution is to sort it and then  check for consecutive elements disregarding the duplicates
    // O(n log n)
    // sort(arr, arr + n);
    // int max_len = 1;
    // int curr_len = 1;
    // int last_smaller = INT_MIN;
    // for(int i = 1; i < n; i++){
    //     if(arr[i] - 1 == last_smaller){
    //         curr_len = curr_len++;
    //         last_smaller = arr[i];
    //     }
    //     else if(arr[i] != last_smaller){
    //         curr_len = 1;
    //         last_smaller = arr[i];
    //     }
    //     max_len = max(max_len, curr_len);
    // }
    // cout << "Length of the longest consecutive elements sequence is: " << max_len << endl;

    // Optimal Solution: Put everything into set data structure to avoid duplicate elements, then iterate over the set and check for consecutive elements 
    // O(n)
    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    int max_len = 0;
    for(auto it = s.begin(); it != s.end(); it++){
        if(s.find(*it - 1) == s.end()){
            int curr_len = 1;
            int next = *it + 1;
            while(s.find(next) != s.end()){
                curr_len++;
                next++;
            }
            max_len = max(max_len, curr_len);
        }
    }
    return 0;
}