class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings
        vector<string> numStrs;
        for(const auto& num : nums) 
            numStrs.push_back(to_string(num));
        
        // Sort strings in descending order
        sort(numStrs.begin(), numStrs.end(), [](const string& a, const string& b) {
            return a + b > b + a; 
        });
        
        // Edge case: nums contains all zeros
        if (numStrs[0] == "0")
            return "0";
        
        // Concatenate all number strings in descending order
        string out;
        for(const auto& numStr: numStrs)
            out += numStr;
        return out;
    }
};