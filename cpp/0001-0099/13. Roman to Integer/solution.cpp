class Solution {
public:
    void nextInt(const string&& sym, const int&& val, const string& s, int& sPtr, int& sum) {
        int symLen = sym.length();
        while (sPtr + symLen <= s.length() && s.substr(sPtr, symLen) == sym) {
            sum += val;
            sPtr += symLen;
        }
    }
    int romanToInt(string s) {
        int sum = 0, sPtr = 0;

        nextInt("M", 1000, s, sPtr, sum);
        nextInt("CM", 900, s, sPtr, sum);
        nextInt("D", 500, s, sPtr, sum);
        nextInt("CD", 400, s, sPtr, sum);
        nextInt("C", 100, s, sPtr, sum);
        nextInt("XC", 90, s, sPtr, sum);
        nextInt("L", 50, s, sPtr, sum);
        nextInt("XL", 40, s, sPtr, sum);
        nextInt("X", 10, s, sPtr, sum);
        nextInt("IX", 9, s, sPtr, sum);
        nextInt("V", 5, s, sPtr, sum);
        nextInt("IV", 4, s, sPtr, sum);
        nextInt("I", 1, s, sPtr, sum);

        return sum;
    }
};