// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long ans = 0;
        while(s[i] == ' '){
            i++;
        }
        int len = 0;
        if(s[i] == '-'){
            i++;
            while(s[i] == '0') i++;
            while(s[i]-'0' >= 0 && s[i] - '0' <=9 && len<=10){
                ans = ans*10 - (s[i]-'0');
                i++;
                len++;
            }
        }
        else if(s[i] == '+'){
            i++;
            while(s[i] == '0') i++;
            while(s[i]-'0' >= 0 && s[i] - '0' <=9 && len<=10){
                ans = ans*10 + (s[i]-'0');
                i++;
                len++;
            }
        }
        else{
            while(s[i] == '0') i++;
            while(s[i]-'0' >= 0 && s[i] - '0' <=9 && len<=10){
                ans = ans*10 + (s[i]-'0');
                i++;
                len++;
            }
        }
        if(ans > INT_MAX){
            ans = INT_MAX;
        }
        else if(ans < INT_MIN){
            ans = INT_MIN;
        }
        return ans;
    }
};