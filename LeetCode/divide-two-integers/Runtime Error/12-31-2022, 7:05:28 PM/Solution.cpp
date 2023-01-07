// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        int i = 0;
        int ans;
        int num = 0;
        bool isNegDivid = false;
        bool isNegDivis = false;
        

        if(divisor == INT_MIN) return 0;
        if(divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if(dividend == INT_MIN){
            if(divisor < 0){
                while(num - INT_MIN >= abs(divisor)){
                    num += divisor;
                    i++;
                }
                ans = i;
            }
            else{
                while((-num) - INT_MIN >= abs(divisor)){
                    num -= divisor;
                    i++;
                }
                ans = -i;
            }
        }
        else{
            if(dividend < 0){
                isNegDivid = true;
                dividend = -dividend;
            }

            if(divisor < 0){
                isNegDivis = true;
                divisor = -divisor;
            }
            while(INT_MAX - num >= divisor && dividend - num >= divisor){
                num += divisor;
                i++;
            }
            if(isNegDivid^isNegDivis) i = -i;
            ans = i;
        }
        return ans;
    }
};