class Solution {
public:
    string convert(string s, int numRows) {
        int m = s.length();
        string ans = "";
        for (int r = 0; r < numRows; r++) {
            int i = r, step = max((numRows - 1) * 2, 1);
            int interStepSize = (numRows - r - 1) * 2;
            while (i < m) {
                ans.push_back(s[i]);
                if (r != 0 && r != numRows - 1) {
                    int interI = i + interStepSize;
                    if (interI < m)
                        ans.push_back(s[interI]);
                }
                i += step;
            }
        }
        return ans;
    }
};