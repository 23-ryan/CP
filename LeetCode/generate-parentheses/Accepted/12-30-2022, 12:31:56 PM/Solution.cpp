// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void solve(int sum, int level, vector<string>& ans, string s, int left, int right, int n){
        if(level == 2*n && sum == 0){
            ans.push_back(s);
        }
        else if(sum == 0 && level != 2*n){
            if(left < n)
                solve(sum+1, level+1, ans, s+"(", left=1, right, n);
        }
        else if(sum > 0 && level != 2*n){
            if(right < n){
                solve(sum-1, level+1, ans, s+")", left, right+1, n);
            }
            if(left < n){
                solve(sum+1, level+1, ans, s+"(", left+1, right, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, ans, "", 0, 0, n);
        return ans;
    }
};