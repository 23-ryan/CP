// https://leetcode.com/problems/container-with-most-water

class Solution {

public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWat = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                maxWat = max(maxWat, min(height[i], height[j])*abs(j-i));
            }
        }
        return maxWat;
    }
};