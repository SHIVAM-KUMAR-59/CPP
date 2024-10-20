/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of elements to enter: ";
    cin >> n;

    int *prices = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cout << "Enter the  elements: " << i+1 << ": ";
        cin >> prices[i];
    }

     int profit = 0;
        int current_price = prices[0];
        for(int i = 1; i < n; i++){
        if(prices[i] < current_price){
            current_price = prices[i];
        }else{
            profit = max(profit, prices[i] - current_price);
        }
    }

    cout <<  "Maximum profit: " << profit << endl;
    return 0;
}