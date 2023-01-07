// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int l = s.length();
        string ans = "";
        int n = numRows;
        for(int j=0; j<n; j++){
            int i = 0;
            while(i < l){
                if(i + j < l)
                    ans += s[i + j];

                if((i+j) + 2*(n-j-1) < l && j!=0 && j!=n-1){
                    ans += s[i+j + 2*(n-j-1)];
                }
                i = i + 2*(n-1);
            }
        }
        return ans;
    }
};