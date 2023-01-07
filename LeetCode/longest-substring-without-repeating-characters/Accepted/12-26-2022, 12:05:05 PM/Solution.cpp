// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int token = 1;
        unordered_map<char,int> vis;
        unordered_map<char, int> index;
        int maxLen = 0;
        int currLen = 0;
        int l = s.length();
        for(int i=0; i<l; i++){
            if(vis[s[i]] != token){
                vis[s[i]] = token;
                index[s[i]] = i;
                currLen++;
            }
            else{
                token++;
                maxLen = max(maxLen, currLen);
                currLen = 0;
                i = index[s[i]];
            }
        }
        return max(maxLen, currLen);
    }
};