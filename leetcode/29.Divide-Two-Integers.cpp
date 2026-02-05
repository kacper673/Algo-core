class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == dividend) return 1;
        if(dividend == -2147483648 && divisor == 1) return -2147483648;
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        if(divisor == 1) return dividend;
        if(divisor == -1) return 0 - dividend;
        if (divisor > 0 && dividend > 0) { //postivie positive
            for (int i = 0; i < pow(2, 31) - 1; i++) {
                if (dividend < 0)
                    return i - 1;
                dividend -= divisor;
            }
        }
        if (divisor < 0 && dividend > 0) { //positive negative
            for (int i = 0; i <= 2147483647; i++) { 
                std::cout<<dividend<<" "<< 1 - i;
                if (dividend < 0)
                    return 1 - i;
                dividend += divisor;
            }
        }
        if (divisor < 0 && dividend < 0) { //negative negative
            for (int i = 0; i <= 2147483647; i++) {
                if (dividend > 0)
                    return i - 1;
                dividend -= divisor;
            }
        }
        if (divisor > 0 && dividend < 0) { //negative positive
            for (int i = 0; i <= 2147483647; i++) {
                if (dividend > 0)
                    return 1 - i;
                dividend += divisor;
            }
        }
        return dividend;
    }
};
