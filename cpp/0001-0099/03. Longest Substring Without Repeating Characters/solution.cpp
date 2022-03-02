class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int n = s.length();
        int count = 0, maxCount = 0;
        for (int i = 0; i < n; i++) {
            if (umap.find(s[i]) != umap.end() && umap[s[i]] >= i - count) {
                count = i - umap[s[i]];
            } else {
                ++count;
                if (count > maxCount) {
                    maxCount = count;
                }
            }
            umap[s[i]] = i; 
        }
        return maxCount;
    }
};