class Solution {
public:
    /* Using backtracking */
    vector<char> digitToLetters(const char& c) {
        vector<char> vec;
        switch (c) {
            case '2':
                vec.insert(vec.end(), {'a', 'b', 'c'});
                break;
            case '3':
                vec.insert(vec.end(), {'d', 'e', 'f'});
                break;
            case '4':
                vec.insert(vec.end(), {'g', 'h', 'i'});
                break;
            case '5':
                vec.insert(vec.end(), {'j', 'k', 'l'});
                break;
            case '6':
                vec.insert(vec.end(), {'m', 'n', 'o'});
                break;
            case '7':
                vec.insert(vec.end(), {'p', 'q', 'r' , 's'});
                break;
            case '8':
                vec.insert(vec.end(), {'t', 'u', 'v'});
                break;
            case '9':
                vec.insert(vec.end(), {'w', 'x', 'y' , 'z'});
                break;
        }
        return vec;
    }
    
    void backtrack(int i, string cs, const string& digits, vector<string>& results) {
        // Base case: already iterated through every digit
        if (i == digits.length()) {
            results.push_back(cs);
            return;
        }
        
        // Recursive case
        vector<char> letters = digitToLetters(digits[i]);
        for (int j = 0; j < letters.size(); j++) {
            backtrack(i + 1, cs + letters[j], digits, results);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        
        if (digits.length() > 0)
            backtrack(0, "", digits, results);
        
        return results;
    }
};