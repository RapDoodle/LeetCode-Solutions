class Solution {
public:
    void nextRomanNum(const int&& val, const string&& sym, int& num, string& s) {
        int n = num / val;
        for (int i = 0; i < n; i++)
            s.append(sym);
        num = num % val;
    }
    
    string intToRoman(int num) {
        // The string in reverse
        string s = "";

        nextRomanNum(1000, "M", num, s);
        nextRomanNum(900, "CM", num, s);
        nextRomanNum(500, "D", num, s);
        nextRomanNum(400, "CD", num, s);
        nextRomanNum(100, "C", num, s);
        nextRomanNum(90, "XC", num, s);
        nextRomanNum(50, "L", num, s);
        nextRomanNum(40, "XL", num, s);
        nextRomanNum(10, "X", num, s);
        nextRomanNum(9, "IX", num, s);
        nextRomanNum(5, "V", num, s);
        nextRomanNum(4, "IV", num, s);
        nextRomanNum(1, "I", num, s);

        return s;
    }
};