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
    /* Brute force approach */
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        
        // Handle the case for ""
        if (digits.size() == 0)
            return combinations;
        
        // Append the letters for the first digit
        vector<char> letters = letterMap.at(digits[0]);
        for (int j = 0; j < letters.size(); j++)
            combinations.push_back(string(1, letters[j]));
        
        // When length >= 2, for every digit, 
        // add every letter in `letters` to every string
        for (int i = 1; i < digits.length(); i++) {
            vector<string> newCombinations;
            vector<char> letters = letterMap.at(digits[i]);
            for (const string& comb: combinations)
                for (const char& letter: letters)
                    newCombinations.push_back(comb + letter);
            
            // Replace the old result with the new one
            combinations = newCombinations;
        }
        return combinations;
    }
};