// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int token = 1;
        unordered_map<char,int> vis;
        int maxLen = 0;
        int currLen = 0;
        for(auto i:s){
            cout << i;
            if(vis[i] != token){
                vis[i]++;
                currLen++;
            }
            else{
                token++;
                maxLen = max(maxLen, currLen);
                currLen = 1;
                vis[i]++;
            }
        }
        return max(maxLen, currLen);
    }
};