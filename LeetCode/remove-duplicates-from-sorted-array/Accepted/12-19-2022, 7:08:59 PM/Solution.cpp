// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> fin;
        int l = nums.size();
        fin.push_back(nums[0]);
        
        int j = 0;
        for(int i=1; i<l; i++){
            cout << i << endl;
            if(nums[i] != fin[j]){
                fin.push_back(nums[i]);
                j++;
            }
        }
        
        l = fin.size();
        
        for(int i=0; i<l; i++){
            nums[i] = fin[i];
        }
        
        return l;
    }
};