// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int ans = 0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            i++;
            while(s[i]-'0' >= 0 && s[i] - '0' <=9){
                ans = ans*10 - (s[i]-'0');
                i++;
            }
        }
        else if(s[i] == '+'){
            i++;
            while(s[i]-'0' >= 0 && s[i] - '0' <=9){
                ans = ans*10 + (s[i]-'0');
                i++;
            }
        }
        else{
            while(s[i]-'0' >= 0 && s[i] - '0' <=9){
                ans = ans*10 + (s[i]-'0');
                i++;
            }
        }
        return ans;
    }
};