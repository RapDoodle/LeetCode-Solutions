class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            // n & (n-1) removes the last bit whose value is 1
            // For example, 
            //  6 = (0110)_2, 5 = (0101)_2, 4 = (0100)_2. Thus,
            //  0110 & 0101 = 0100.
            n &= n - 1;
            ++count;
        }
        return count;
    }
};