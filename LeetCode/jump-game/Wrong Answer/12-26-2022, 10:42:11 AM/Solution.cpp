// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        for(int i=0; i<l-1; i++){
            if(nums[i] == 0){
                return false;
            }
        }
        return true;
    }
};