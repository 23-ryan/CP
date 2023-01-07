// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int token = 1;
        vector<int> vis(26, 0);
        int maxLen = 0;
        int currLen = 0;
        for(auto i:s){
            if(vis[i - 'a'] != token){
                vis[i - 'a']++;
                currLen++;
            }
            else{
                token++;
                maxLen = max(maxLen, currLen);
                currLen = 1;
                vis[i-'a']++;
            }
        }
        return maxLen;
    }
};