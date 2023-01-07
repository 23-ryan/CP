// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenP = p.length();
        int lenS = s.length();
        char prevChar = s[0];
        int j = 0;
        bool ans = true;
        for(int i=0; i<lenP; i++){
            if(p[i] == '.'){
                prevChar = '.';
                j++;
            }
            else if(p[i] == '*'){
                if(prevChar == '.'){
                    ans = true;
                    i = lenP;
                    j = lenS;
                    break;
                }
                else{
                    int c1=i+1, c2=j, count1=0, count2=0;
                    while(c1 < lenP && p[c1] == prevChar){
                        c1++;
                        count1++;
                    }
                    while(s[c2] == prevChar){
                        c2++;
                        count2++;
                    }
                    if(count1 > count2){
                        ans = false;
                        i = lenP;
                        j = lenS;
                        break;
                    }
                    else{
                        i = c1-1;
                        j = c2;
                    }
                    
                }
            }
            else if(i+1 < lenP && p[i] != s[j] && p[i+1] == '*'){
                i+=2;
            }
            else{
                if(s[j] != p[i]){
                    ans = false;
                    i = lenP;
                    j = lenS;
                    break;
                }
                else{
                    prevChar = s[j];
                    j++;
                }
            }
        }
        if(j != lenS) ans = false;
        return ans;
    }
};