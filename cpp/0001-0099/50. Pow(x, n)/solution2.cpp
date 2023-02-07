class Solution {
public:
    double myPow(double x, int n) {
        // Properties:
        //  1. 0^n = 0 (base case)
        //  2. x^0 = 1 (base case)
        //  3. When n is an even number, 
        //      x^(n/2) * x^(n/2) = x^n
        //  4. When n is an odd number, 
        //      x^(int(n/2)) * x^(int(n/2)) * x = x^n
        //  5. 1^n = 1
        if (n == 0)
            return 1.0;
        if (abs(abs(x) - 1.0) == 1e-20)
            return 1.0;
        long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        
        // Use 77 as an example: (77)_10 = (1001101)_2,
        //  x^77 = x^1 * x^4 * x^8 * x^64, which corresponds
        //  to the ones in the binary representation
        double currPow = x, ans = 1.0;
        while (N > 0) {
            if (N % 2 == 1)
                ans *= currPow;
            currPow *= currPow;
            N = N >> 1;
        }
        
        return ans;
    }
};