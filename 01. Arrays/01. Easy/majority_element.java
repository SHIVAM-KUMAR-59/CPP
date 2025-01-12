/*
 Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 */

class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int element = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == element){
                count++;
            }else{
                count--;
                if(count == 0){
                    element = nums[i];
                    count = 1;
                }
            }
        }
        return element;
    }
}