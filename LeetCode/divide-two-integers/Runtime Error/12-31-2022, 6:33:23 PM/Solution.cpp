// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        int i = 0;
        int num = 0;
        
        if(divisor == INT_MIN) return 0;

        bool isNegDivis = false;
        bool isNegDivid = false;
        if(divisor < 0){
            isNegDivis = true;
            divisor = -divisor;
        }
        if(dividend < 0){
            isNegDivid = true;
            dividend = -dividend;
        }
        
        while(true){
            num += divisor;
            if(num > dividend) break;
            i++;
        }

        if(isNegDivid^isNegDivis){
            i = -i;
        }
        return i;
    }
};