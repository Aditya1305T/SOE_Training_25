class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size()-1;
        int i = n;
        while(i >=0 && carry != 0){
            digits[i]+=carry;
            carry = digits[i]/10;

            if(i != 0)
                digits[i] %= 10;
            i--;
        }

        if(digits[0] > 9){
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};