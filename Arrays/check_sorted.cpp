// Check if the array is sorted (ascending) or not 

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  element " << i+1 << ": ";
        cin >> arr[i];
    }

    int flag = 0;

    for(int i = 1; i < n; i++){
        if(!(arr[i - 1] <= arr[i])){
            flag = 1;
        }
    }

    if(flag == 1){
        cout << "The array is not sorted in non descending order." << endl;
    }else{
        cout << "The array is sorted in non descending order." << endl;
    }

    return 0;
}