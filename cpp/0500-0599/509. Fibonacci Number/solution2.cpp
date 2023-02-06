class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        
        // When n = 2, 
        //  prev2 = fib(n-2) = fib(0) = 0
        //  prev1 = fib(n-1) = fib(1) = 1
        // fib(n) = fib(n-1) + fib(n-2)
        int prev2 = 0, prev1 = 1, curr;
        n -= 2;
        while (n >= 0) {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
            --n;
        }

        return curr;
    }
};