// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        for(int i=l-1; i>=0; i--){
            if(nums[i] != 0){
                while(i-1 >= 0){
                    if(nums[i-1] == 0){
                        return false;
                    }
                    i--;
                }
                return true;
            }
        }
        return true;
    }
};