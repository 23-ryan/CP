// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        bool ans;
        if (x < 0) ans = false;
        else{
            string s = to_string(x);
            int l = s.length();
            ans = true;
            for(int i=0; i<l/2; i++){
                if(s[i] != s[l-i-1]){
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};