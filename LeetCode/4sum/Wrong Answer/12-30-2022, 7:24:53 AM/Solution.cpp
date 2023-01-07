// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = nums.size();

        unordered_map<int, bool> arr;
        for(auto i:nums){
            arr[i] = false;
        }
        vector<vector<int>> ans;
        vector<int> a(4, 0);
        int prevI = INT_MIN, prevJ = INT_MAX;
        for(int i=0; i<l-3; i++){
            for(int j=i+1; j<l-2; j++){
                int st = j+1;
                int en = l-1;
                while(st < en){
                    if(nums[i] + nums[j] + nums[st] + nums[en] - target < 0){
                        st++;
                    }
                    else if(nums[i] + nums[j] + nums[st] + nums[en] - target > 0){
                        en--;
                    }
                    else if(prevI == nums[i] && prevJ == nums[j]){
                        st++;
                        en--;
                    }
                    else if(!(arr[i] && arr[j])){
                        a[0] = nums[i];
                        a[1] = nums[j];
                        a[2] = nums[st];
                        a[3] = nums[en];
                        ans.push_back(a);
                        prevI = nums[i];
                        prevJ = nums[j];
                        st++;
                        en--;
                    }
                }
                arr[nums[i]] = true;
                arr[nums[j]] = true;
            }
        }

        return ans;

    }
};