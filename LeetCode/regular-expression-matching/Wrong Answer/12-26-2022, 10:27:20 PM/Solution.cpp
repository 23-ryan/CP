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
            if(p[j] == '.' || s[i] == p[j]){
                prevChar = s[i];
            }
            else if(p[j] == '*'){
                int sCount =0, pCount=0;
                j = j+1;
                while(j + pCount < l2 && p[j] == prevChar) pCount++;
                while(i + sCount < l1 && s[i] == prevChar) sCount++;

                if(pCount > sCount){
                    ans = false;
                    break;
                }
                i = sCount + i;
                j = pCount + j;
            }
            else{
                if(s[i] != p[j]){
                    if(!(j+1 < l2 && p[j+1] == '*')){
                        ans = false;
                        break;
                    }
                    j++;
                }
            }
            i++; j++;
        }
        if(i<l1 || j<l2){
            ans = false;
        }
        return ans;
    }
};