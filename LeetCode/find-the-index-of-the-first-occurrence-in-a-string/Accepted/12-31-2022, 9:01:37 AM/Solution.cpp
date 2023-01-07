// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans;
        if(string::npos == haystack.find(needle)) ans = -1;
        else ans = haystack.find(needle);
        return ans;
    }
};