// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        int en = 0;
        int n = nums.size();
        while(st < n && en < n){
            while(nums[st] != 0 && st < n) st++;
            while((nums[en] == 0 || en <= st) && en < n) en++;
            
            if(st < n && en < n){
                int temp = nums[en];
                nums[en] = nums[st];
                nums[st] = temp;
                st++;
                en++;
            }
        }
    }
};