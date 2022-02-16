class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        // i points at the greediest child
        // j points at the largest cookie
        int satisfied = 0, i = g.size() - 1, j = s.size() - 1;
        while (i >= 0 && j >= 0) {
            if (g[i] <= s[j]) {
                satisfied++;
                // The current bag of cookies has been used
                j--;
            }
            i--;
        }
        
        return satisfied;
    }
};