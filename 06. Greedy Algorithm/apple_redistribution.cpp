/*
You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        int n = apple.size();
        int m = capacity.size();

        for(int i = 0; i < n; i++){
            totalApples += apple[i];
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxes = 0;
        for(int i = 0; i < m; i++){
            if(totalApples > 0){
                totalApples -= capacity[i];
                boxes++;
            }else{
                break;
            }
        }
        return boxes;
    }
};