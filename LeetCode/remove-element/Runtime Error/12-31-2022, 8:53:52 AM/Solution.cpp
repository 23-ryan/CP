// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size();
        int st = 0, en = l-1;
        while(st < en){
            while(nums[en] == val) en--;
            while(nums[st] != val) st++;

            if(st < en){
                int swap = nums[st];
                nums[st] = nums[en];
                nums[en] = swap;
                st++;
                en--;
            }
        }
        int k;
        for(k=0; k<l; k++){
            if(nums[k] == val) break;
        }
        return k;
    }
};