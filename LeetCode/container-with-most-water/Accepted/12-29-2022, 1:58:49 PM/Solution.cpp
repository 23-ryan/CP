// https://leetcode.com/problems/container-with-most-water

class Solution {

public:
    int maxArea(vector<int>& height) {
        int maxWat = 0;
        int i = 0, j = height.size()-1;
        while(i < j){
            maxWat = max(maxWat, min(height[i], height[j])*(j-i));
            if(height[i] <= height[j]) i++;
            else j--;
        }

        return maxWat;
    }
};