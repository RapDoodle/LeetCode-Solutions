class Solution {
public:
    /* Dynamic programming */
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        // Essentially solving:
        //  f(n) = f(n-1) + f(n-2) [Fibonacci sequence]
        int prev1 = 1, prev2 = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = prev1;
            prev1 = prev1 + prev2;
            prev2 = temp;
        }
        
        return prev1;
    }
};