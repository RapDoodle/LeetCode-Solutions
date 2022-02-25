class Solution {
public:
    /* Newton's method */
    int mySqrt(int x) {
        long a = x;
        while (a * a > x) {
            // f(x_{n}) = x_{n}^2 - a
            // Update a towards a smaller value using
            // x_{n+1} = x_{n} - (f(x_{n}))/(f'(x_{n}))
            //         = x_{n} - (x_{n}^2 - a) / (2x_{n})
            //         = (x_{n} + a / x_{n}) / 2
            a = (a + x / a) / 2;
        }
        return a;
    }
};