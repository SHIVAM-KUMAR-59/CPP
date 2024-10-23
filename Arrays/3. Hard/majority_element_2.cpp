// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

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

    // Brute force is checking for every element individually O(n^2)
    // Hashmap is always an option but it will be O(nlogn)
    // Optimal Aproaxh - We can use Boyer-Moore Majority Vote Algorithm which is O(n)
    // Approach -  At max there can be only 2 such elements which satisfy the condition.
    int element1 = 0, element2 = 0, count1 = 0,  count2 = 0;
    for(int i = 0; i < n; i++){
        if(count1 == 0 && arr[i] != element2){
            count1 = 1;
            element1 = arr[i];
        }
        else if(count2 == 0 && arr[i] != element1){
            count2 = 1;
            element2 = arr[i];
        }
        else if(arr[i] == element1){
            count1++;
        }
        else if(arr[i] == element2){
            count2++;
        }else{
            count1--;
            count2--;
        }
    }

    int verify_count1 = 0, verify_count2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == element1){
            verify_count1++;
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == element2){
            verify_count2++;
        }
    }
    if(verify_count1 > n/3 && verify_count2 > n/3){
        cout << "Two elements are " << element1 << " and " << element2 << endl;
    }

    return 0;
}