// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            string s = "1";
            return s;
        }
        string prev = countAndSay(n-1);
        int l = prev.length();
        char prevChar = prev[0];
        int cnt = 0;
        string ans = "";
        for(int i=0; i<l; i++){
            if(prevChar == prev[i]) cnt++;
            else{
                ans += char(cnt + '0');
                ans += prevChar;
                prevChar = prev[i];
                cnt = 1;
            }
        }
        cout << ans << endl;
        ans += char(cnt + '0');
        ans += prevChar;

        return ans;
    }
};