// https://leetcode.com/problems/plus-one

class Solution {
public:
     vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        int carry = 1;
        int i = l-1;

        while(carry > 0 && i >= 0){
            int dig = digits[i];
            digits[i] = (dig + carry)%10;
            carry = (dig + carry)/10;
            i--;
        }
        if(carry > 0){
            digits.push_back(0);
            for(int i=l; i>0; i--){
                digits[i] = digits[i-1];
            }
            digits[0] = carry;
        }
        return digits;
}
};