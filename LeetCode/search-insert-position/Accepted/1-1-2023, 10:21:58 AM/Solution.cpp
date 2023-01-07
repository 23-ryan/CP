// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = nums.size();
        int st=0, en=l-1;
        int mid = st + (en-st)/2;
        int ans  = -1;
        while(st <= en){
            mid = st + (en-st)/2;
            if(nums[mid] == target){
                break;
            }

            if(nums[mid] < target) st = mid + 1;
            else if(nums[mid] > target) en = mid -1;
        }
        if(nums[mid] >= target) ans = mid;
        if(nums[mid] < target) ans = mid+1;

        return ans;
    }
};