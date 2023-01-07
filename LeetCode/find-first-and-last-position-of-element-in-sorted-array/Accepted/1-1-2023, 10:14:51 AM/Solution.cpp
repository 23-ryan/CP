// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int greatRange = -1;
        int lessRange = -1;
        int l = nums.size();
        int st = 0, en = l-1;
        vector<int> ans;
        int mid = st + (en-st)/2;
        while(st <= en){
            mid = st + (en-st)/2;
            if(nums[mid] <= target) st = mid+1;
            else if(nums[mid] > target) en = mid-1;
        }
        if(l!=0 && nums[mid] == target){
            greatRange = mid;
        }
        else if(l!=0 && nums[mid] != target){
            if(mid > 0 && nums[mid-1] == target) greatRange = mid-1;
            else greatRange = -1;
        }

        cout << greatRange << endl;
        if(greatRange != -1){
            st = 0;
            en = l-1;
            int mid = st + (en-st)/2;
            while(st <= en){
                mid = st + (en-st)/2;
                if(nums[mid] < target) st = mid+1;
                else if(nums[mid] >= target) en = mid-1;
            }
            if(nums[mid] == target){
                lessRange = mid;
            }
            else if(nums[mid] != target){
                if(mid < l-1 && nums[mid+1] == target) lessRange = mid+1;
                else lessRange = -1;
            }
            ans.push_back(lessRange);
            ans.push_back(greatRange);

        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};