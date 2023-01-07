// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-1;
        while(i >= 1){
            if(nums[i-1] < nums[i]){
                int minDiff = INT_MAX;
                int index = -1;
                for(int j=i; j<n; j++){
                    if(nums[j] - nums[i-1] > 0 && (nums[j] - nums[i-1]) < minDiff){
                        index = j;
                        minDiff = nums[j] - nums[i-1];
                    }
                }
                
                int temp = nums[index];
                nums[index] = nums[i-1];
                nums[i-1] = temp;
                sort(nums.begin() + i, nums.end());
                break;
            }
            i--;
        }
        if(i == 0){
            sort(nums.begin(), nums.end());
        }

    }
};