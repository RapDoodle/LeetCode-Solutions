const unordered_map<char, vector<char>> letterMap {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r' , 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y' , 'z'}},
};

class Solution {
public:
    /* Using backtracking */
    void backtrack(int i, string cs, const string& digits, vector<string>& results) {
        // Base case: already iterated through every digit
        if (i == digits.length()) {
            results.push_back(cs);
            return;
        }
        
        // Recursive case
        vector<char> letters = letterMap.at(digits[i]);
        for (const char& letter: letters) {
            backtrack(i + 1, cs + letter, digits, results);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        
        if (digits.length() > 0)
            backtrack(0, "", digits, results);
        
        return results;
    }
};