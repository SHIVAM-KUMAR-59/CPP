// Remove duplicates from a sorted array

#include <iostream>
#include <set>
using namespace std;

int main(){
    
    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  element in ascending order " << i+1 << ": ";
        cin >> arr[i];
    }

    // Brute Force - O(nlogn + n)
    // set<int> st;
    // for(int i = 0; i < n; i++){
    //     st.insert(arr[i]);
    // }

    // int index = 0;
    // for(auto it : st){
    //     arr[index++] = it;
    // }

    // Optimal Approach (2 Pointer Approach) - O(n)
    int i = 0;
    for(int j = 1; j < n - 1; j++){
        if(arr[j] != arr[i]){
            arr[i + 1] = arr[j];
            i++;
        }
    }

}