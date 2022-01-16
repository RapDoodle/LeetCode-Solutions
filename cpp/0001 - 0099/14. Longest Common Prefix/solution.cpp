class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        
        // 0 <= strs[i].length <= 200
        if (strs.size() == 1)
            return strs[0];
        
        while (true) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i - 1][idx] == '\0' || strs[i][idx] != strs[i - 1][idx]) {
                    return strs[i - 1].substr(0, idx);
                }
            }
            idx++;
        }
    }
};