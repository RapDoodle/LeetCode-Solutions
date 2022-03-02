// Credits: https://youtu.be/n9fYwG3dC_Q
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> states;
        for (const string& word : words)
            states[word]++;
        
        // The length of the string
        int m = s.length();
        
        // The length of the words (expected to be equal length)
        int n = words[0].length();
        
        // The number of words
        int numWords = words.size();
        
        // Loop over the substrings that start from index 0, 1, ..., n
        for (int i = 0; i < n; ++i) {
            int count = 0;
            unordered_map<string, int> localStates = states;
            
            // Loop over every n character in the string
            for (int j = i; j <= m - n; j += n) {
                string currStr = s.substr(j, n);
                
                localStates[currStr]--;
                if (localStates[currStr] >= 0)
                    ++count;
                
                int popStart = j - numWords * n;
                
                // Check for valid starting index first 
                if (popStart >= 0) {
                    string popWord = s.substr(popStart, n);
                    
                    if (localStates.find(popWord) != localStates.end()) {
                        ++localStates[popWord];
                        if (localStates[popWord] > 0) {
                            // Pop away an useful word
                            --count;
                        }
                    }
                }
                
                // When all entries in localStates are 0
                if (count == numWords)
                    ans.push_back(popStart + n);
            }
        }
        return ans;
    }
};