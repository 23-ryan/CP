// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        vector<bool> dp(target, 0);
        
        vector<int> ans;
        for(auto i : nums){
            if(i < target)
                dp[i-1] = true;
        }
        
        for(int i=0; i<l; i++){
            if(target - nums[i] - 1 < target && dp[target - nums[i] - 1] == true){
                for(int j=0; j<l; j++){
                    if(target - nums[i] == nums[j] && i != j){
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};