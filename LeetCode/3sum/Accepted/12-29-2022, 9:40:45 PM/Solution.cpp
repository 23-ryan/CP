// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int l = nums.size();
        unordered_map<int, bool> arr;
        for(int i=0; i<l; i++){
            arr[nums[i]] = false;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<l-1; i++){
            int st = i+1;
            int en = l-1;
            int prevSt = INT_MIN, prevEn = INT_MAX;
            vector<int>a(3, 0);
            while(st < en){
                if(nums[st] + nums[en] + nums[i] > 0) en--;
                else if(nums[st] + nums[en] + nums[i] < 0) st++;
                else if(nums[st] == prevSt && nums[en] == prevEn){
                    st++;
                    en--;
                }
                else if(!arr[nums[i]]){
                    a[0] = (nums[st]);
                    a[1] = (nums[en]);
                    a[2] = (nums[i]);
                    ans.push_back(a);
                    prevSt = nums[st];
                    prevEn = nums[en];
                    st++;
                    en--;
                }
                else{
                    break;
                }
            }
            arr[nums[i]] = true;
        }
        return ans;
    }
};