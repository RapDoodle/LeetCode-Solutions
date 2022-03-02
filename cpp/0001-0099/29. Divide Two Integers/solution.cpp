class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // `true` when the dividend and divisor has the same sign
        bool sign = (dividend >= 0) == (divisor >= 0);
        
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        
        long quot = 0;
        
        while (dvd - dvs >= 0) {
            int count = 0;
            while (dvd - (dvs << count << 1) >= 0)
                ++count;
            
            quot += 1 << count;
            dvd -= dvs << count;
        }
        
        return sign ? quot : -quot;
    }
};