class Solution {
private:
    static constexpr int factors[] = {2, 3, 5};
public:
    bool isUgly(int n) {
        // If it is an ugly number, it can be written as
        //  n = 2^a + 3^b + 5^c (n > 0)
        if (n <= 0) 
            return false;

        for (const int& factor : factors)
            while (n % factor == 0)
                n /= factor;
        return n == 1;
    }
};