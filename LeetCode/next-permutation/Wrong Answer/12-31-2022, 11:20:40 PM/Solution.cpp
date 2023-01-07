// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-1;
        while(i >= 1){
            if(nums[i-1] < nums[i]){
                int minNum = INT_MAX;
                int index;
                for(int j=i; j<n; j++){
                    if(nums[j] != nums[i-1] && minNum > nums[j]){
                        minNum = nums[j];
                        index = j;
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