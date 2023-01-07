// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int minDiff = INT_MAX;
        int l = nums.size();
        for(int i=0; i<l; i++){
            int st = i+1;
            int en = l-1;
            while(st < en){
                if(abs(nums[st] + nums[en] + nums[i] - target) < minDiff){
                    ans = nums[st] + nums[en] + nums[i];
                    minDiff = abs(nums[st] + nums[en] + nums[i] - target);
                }
                if(nums[st] + nums[en] + nums[i] - target < 0) st++;
                else if(nums[st] + nums[en] + nums[i] - target > 0) en--;
                else break;
            }
        }
        return ans;
    }
};