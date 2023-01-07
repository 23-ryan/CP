// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        unordered_map<int, bool> dp;
        
        vector<int> ans;
        for(auto i : nums){
            dp[i] = true;
        }
        
        for(int i=0; i<l; i++){
            if(dp[target - nums[i]] == true){
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