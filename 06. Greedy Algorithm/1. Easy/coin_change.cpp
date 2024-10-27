/*
Given an array coins[] of size N and a target value sum, where coins[i] represents the coins of different denominations. You have an infinite supply of each of coins. The task is to find minimum number of coins required to make the given value sum. If it’s not possible to make a change, print -1.
*/

#include<iostream>
using namespace std;

struct Item{
    int value;
    int weight;
};


class Solution {
  public:
    int fractionalKnapsack(vector<int>coins, int v) {
      int n = coins.size();
      int ans = 0;
      for(int i = n - 1; i >= 0; i++){
        while(v >=  coins[i]){
          v -= coins[i];
          ans++;
        }
      }
      return ans;
    }
};