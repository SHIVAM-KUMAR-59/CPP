// Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

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

    // Brute force will be the counting each and every element one by one - O(n^2)
    // Better Solution can be using a Hashmap - O(nlogn)
    // Optimal Approach - Moore's Voting Algorithm
    int count = 0;
    int verify_count = 0;
    int element;
    for(int i = 0; i < n; i++){
        if(count == 0){
            count = 1;
            element = arr[i];
        }else{
            if(arr[i] == element){
                count++;
            }else{
                count --;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == element){
            verify_count++;
        }
    }

    if(verify_count > n/2){
        cout << "Majority Element is: " << element;
    }else{
        cout << "Majority Element does not exist";
    }

    return 0;
}