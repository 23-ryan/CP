// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long ans = 0;
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
        if(ans > INT_MAX){
            ans = INT_MAX;
        }
        else if(ans < INT_MIN){
            ans = INT_MIN;
        }
        return ans;
    }
};