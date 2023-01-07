// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i: s){
            if(!st.empty()){
                char x = st.top();
                if((x == '[' && i==']') || (x == '(' && i==')') || (x == '{' && i=='}')){
                    st.pop();
                    continue;
                }
            }
            st.push(i);
        }
        return st.empty();
    }
};