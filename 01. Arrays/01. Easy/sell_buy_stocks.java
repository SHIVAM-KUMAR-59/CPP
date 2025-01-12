/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

 class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int diff = 0;
        int currentPrice = prices[0];
        for(int i = 0; i < n; i++){
            if(prices[i] < currentPrice){
                currentPrice = prices[i];
            }else{
                int temp = prices[i] - currentPrice;
                if(diff < temp){
                    diff = temp;
                }
            }
        }
        return diff;
    }
}