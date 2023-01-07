// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> arr;
        arr[1] = 'I';
        arr[5] = 'V';
        arr[10] = 'X';
        arr[50] = 'L';
        arr[100] = 'C';
        arr[500] = 'D';
        arr[1000] = 'M';

        unordered_map<int, int> grr;
        grr[0] = 1;
        grr[1] = 5;
        grr[2] = 10;
        grr[3] = 50;
        grr[4] = 100;
        grr[5] = 500;
        grr[6] = 1000;

        int i = 6;
        int add;
        string ans = "";
        while(num != 0){
            if(num >= 9 && num < 10){
                ans += "IX";
                num = num - 9;
            }
            else if(num >= 90 && num < 100){
                ans += "XC";
                num = num - 90;
            }
            else if(num >= 900 && num < 1000){
                ans += "CM";
                num = num - 900;
            }
            else if(num >= 4 && num < 5){
                ans += "IV";
                num = num - 4;
            }
            else if(num >= 40 && num < 50){
                ans += "XL";
                num = num - 40;
            }
            else if(num >= 400 && num < 500){
                ans += "CD";
                num = num - 400;
            }
            else{
                add = num/grr[i];
                if(add != 0){
                    for(int j=0; j<add; j++){
                        ans += arr[grr[i]];
                    }
                }
                num = num%grr[i];
            }
            i--;
            
        }
        return ans;
        
    }
};