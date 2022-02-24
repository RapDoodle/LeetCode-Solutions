class Solution {
public:
    /* Two-pointers */
    bool judgeSquareSum(int c) {
        // When a = 0, we have b^2 = c. Thus, the maximum
        // number allowed for b is b <= sqrt(c) 
        long a = 0, b = sqrt(c);
        while (a <= b) {
            long sqrd = a*a + b*b;
            if (sqrd == c) {
                return true;
            } else if (sqrd < c) {
                ++a;
            } else {
                --b;
            }
        }
        return false;
    }
};