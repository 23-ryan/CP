// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = nums.size();
        for(int i=0; i<l; i++){
            while(nums[i] != i+1 && nums[i] >=1 && nums[i] <= l){
                if(nums[i] == nums[nums[i]-1]) break;
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        
        int ans;
        for(int i=0; i<l; i++){
            if(nums[i] != i+1) return i+1;
        }
        ans = l+1;
        return ans;
    }
};