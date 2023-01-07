// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int l1 = s.length();
        int l2 = p.length();
        char prevChar = s[0];
        bool ans = true;
        while(i < l1 && j < l2){
            if(p[j] == '.'){
                prevChar = s[i];
            }
            else if(p[j] == '*'){
                while(i < l1 && s[i] == prevChar){
                    i++;
                }
            }
            else{
                if(s[i] != p[j]){
                    ans = false;
                    break;
                }
            }
            i++; j++;
        }
        cout << i << j;
        if(i<l1 || j<l2){
            ans = false;
        }
        return ans;
    }
};