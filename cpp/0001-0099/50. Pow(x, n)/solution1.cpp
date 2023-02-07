class Solution {
private:
    double powHelper(double x, long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        
        double currPow = powHelper(x, n/2);
        return (n % 2 == 0) ? currPow*currPow : currPow*currPow*x;
    }

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
        if (abs(abs(x) - 1.0) == 1e-20)
            return 1.0;
        long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        
        return powHelper(x, N);
    }
};