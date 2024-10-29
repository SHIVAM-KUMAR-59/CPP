/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/

#include<iostream>
using namespace std;

// SC: O(2n)
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         int leftNeighbour[n];
//         leftNeighbour[0] = 1;
//         // int rightNeighbour[n];
//         // rightNeighbour[n - 1] = 1;
        
//         // for(int i = 1; i < n; i++){
//         //     if(ratings[i] > ratings[i - 1]){
//         //         leftNeighbour[i] = leftNeighbour[i - 1] + 1;
//         //     }
//         //     else{
//         //         leftNeighbour[i] = 1;
//         //     }
//         // }

//         // for(int i = n - 2; i >= 0; i--){
//         //     if(ratings[i] > ratings[i + 1]){
//         //         rightNeighbour[i] = rightNeighbour[i + 1] + 1;
//         //     }
//         //     else{
//         //         rightNeighbour[i] = 1;
//         //     }
//         // }

//         // int sum = 0;
//         // for(int i = 0; i < n; i++){
//         //     sum += max(leftNeighbour[i], rightNeighbour[i]);
//         // }

//         for(int i = 1; i < n; i++){
//             if(ratings[i] > ratings[i - 1]){
//                 leftNeighbour[i] = leftNeighbour[i - 1] + 1;
//             }
//             else{
//                 leftNeighbour[i] = 1;
//             }
//         }

//         int right = 1, current = 1, sum = max(1, leftNeighbour[n - 1]);
//         for(int i = n - 2; i >= 0; i--){
//             if(ratings[i] > ratings[i + 1]){
//                 current += 1;
//                 right = current;
//             }else{
//                 current = 1;
//             }
//             sum +=  max(leftNeighbour[i], current);
//         }

//         return sum;
//     }
// };

// SC: O(n)
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         int leftNeighbour[n];
//         leftNeighbour[0] = 1;
    
//         for(int i = 1; i < n; i++){
//             if(ratings[i] > ratings[i - 1]){
//                 leftNeighbour[i] = leftNeighbour[i - 1] + 1;
//             }
//             else{
//                 leftNeighbour[i] = 1;
//             }
//         }

//         int right = 1, current = 1, sum = max(1, leftNeighbour[n - 1]);
//         for(int i = n - 2; i >= 0; i--){
//             if(ratings[i] > ratings[i + 1]){
//                 current += 1;
//                 right = current;
//             }else{
//                 current = 1;
//             }
//             sum +=  max(leftNeighbour[i], current);
//         }

//         return sum;
//     }
// };

// SC: O(1)
// Slope based approach
class Solution{
    public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i - 1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i - 1]){
                sum += down;
                i++;
                down++;
            }

            if(down > peak){
                sum += (down - peak);
            }
        }
        return sum;
    }
};