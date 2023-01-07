// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> arr;
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;

        int l = s.length();
        int i = 0;
        int ans = 0;
        while(i != l){
            if(i+1 < l && s[i] == 'I' && s[i+1] == 'V'){ans += 4; i+=2;}
            else if(i+1 < l && s[i] == 'I' && s[i+1] == 'X'){ans += 9; i+=2;}
            else if(i+1 < l && s[i] == 'X' && s[i+1] == 'L'){ans += 40; i+=2;}
            else if(i+1 < l && s[i] == 'X' && s[i+1] == 'C'){ans += 90; i+=2;}
            else if(i+1 < l && s[i] == 'C' && s[i+1] == 'D'){ans += 400; i+=2;}
            else if(i+1 < l && s[i] == 'C' && s[i+1] == 'M'){ans += 900; i+=2;}
            else{
                ans += arr[s[i]];
                i++;
            }
        }
        return ans;
    }
};