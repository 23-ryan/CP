// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = nums.size();

        unordered_map<int, bool> arrI;
        unordered_map<int, bool> arrJ;
        for(auto i:nums){
            arrI[i] = false;
            arrJ[i] = false;
        }
        vector<vector<int>> ans;
        vector<int> a(4, 0);
        for(int i=0; i<l-3; i++){
            if(arrI[nums[i]]) continue;
            for(int j=i+1; j<l-2; j++){
                int st = j+1;
                int en = l-1;
                int prevS = INT_MIN, prevE = INT_MAX;
                while(st < en){
                    long long chk = nums[i] + nums[j] + nums[st] + nums[en] - target;
                    if(chk < 0){
                        st++;
                    }
                    else if(chk > 0){
                        en--;
                    }
                    else if(prevS == nums[st] && prevE == nums[en]){
                        st++;
                        en--;
                    }
                    else if(!(arrJ[nums[j]])){
                        a[0] = nums[i];
                        a[1] = nums[j];
                        a[2] = nums[st];
                        a[3] = nums[en];
                        ans.push_back(a);
                        prevS = nums[st];
                        prevE = nums[en];
                        st++;
                        en--;
                    }
                    else{
                        break;
                    }
                }
                arrJ[nums[j]] = true;
            }
            for(int j: nums){
                arrJ[j] = false;
            }
            arrI[nums[i]] = true;
        }

        return ans;

    }
};