class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            // Check if the last bit is 1
            if (n & 1)
                ++count;
            // Shift to the right
            n = n >> 1;
        }
        return count;
    }
};