// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        if(x == 0) return 0;
        int ans = 0;
        bool neg = (x < 0);
        if(neg) x = -x;
        cout << int(log10(x))+1 << endl;
        if(int(log10(x))+1 < 10){
            while(x != 0){
                ans = 10*ans + x%10;
                x = x/10;
            }
            cout << ans;
        }
        else{
            string s = to_string(INT_MAX);
            cout << s << endl;
            int temp = x;
            int i=0;
            while(x != 0){
                if(x%10 > (s[i]-'0')){
                    ans = 0;
                    break;
                }
                x /= 10;
                i++;
            }
        }
        if(neg) ans = -ans;
    
        return ans;
    } 
};