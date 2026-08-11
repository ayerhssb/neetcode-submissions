class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int result = a^b;
            int carry = (a&b)<<1;
            a = result;
            b = carry;
        }
        return a;
    }
};
