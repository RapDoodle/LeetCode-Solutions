class Solution {
public:
    /* Greedy */
    vector<int> partitionLabels(string s) {
        // The first pass: iterate through the string to find
        // the index of each characters' last occurence
        unordered_map<char, int> last;
        for (int i = 0; i < s.length(); ++i)
            last[s[i]] = i;
        
        // The second pass: partition
        vector<int> ans;
        int size = 0, end = last[s[0]];
        for (int i = 0; i < s.length(); ++i) {
            ++size;
            if (last[s[i]] > end) {
                // The character's last index is beyond the 
                // current end (range).
                // For example:
                //  01234
                //  ababc 
                //   ^
                //   |
                //  The current end should be 2, but b can be
                //  found at index 3, update end to 3.
                end = last[s[i]];
            }
            if (i == end) {
                // All characters within the current range will
                // not appear again.
                // For example:
                //  ababc
                //     ^
                //     |
                ans.push_back(size);
                size = 0;
            }
        }
        
        return ans;
    }
};