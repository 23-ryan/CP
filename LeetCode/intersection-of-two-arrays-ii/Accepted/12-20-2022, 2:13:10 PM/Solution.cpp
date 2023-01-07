// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ma;
        vector<int> ans;
        for(auto i: nums1){
            ma[i]++;
        }
        for(auto i: nums2){
            if(ma[i] != 0){
                ma[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};