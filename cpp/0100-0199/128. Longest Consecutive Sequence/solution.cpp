class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a hash table to store unique numbers
        unordered_set<int> s;
        for (const auto& num : nums)
            s.insert(num);
        
        int maxSeqLen = 0, seqLen, cur;
        for (const auto& num : s) {
            if (s.find(num-1) == s.end()) {
                // The beginning of a potential sequence
                seqLen = 1;
                cur = num;
                
                // Look for the end of the sequence
                while (s.find(++cur) != s.end())
                    ++seqLen;
                maxSeqLen = max(maxSeqLen, seqLen);
            }
        }
        
        return maxSeqLen;
    }
};