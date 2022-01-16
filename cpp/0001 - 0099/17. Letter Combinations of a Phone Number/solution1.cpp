class Solution {
public:
    /* Brute force approach */
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
    
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        
        // Handle the case for ""
        if (digits.size() == 0)
            return vec;
        
        // Append the letters for the first digit
        vector<char> letters = digitToLetters(digits[0]);
        for (int j = 0; j < letters.size(); j++)
            vec.push_back(string(1, letters[j]));
        
        // When length >= 2, for every digit, 
        // add every letter in `letters` to every string
        for (int i = 1; i < digits.length(); i++) {
            vector<string> newVec;
            vector<char> letters = digitToLetters(digits[i]);
            for (int j = 0; j < vec.size(); j++)
                for (int k = 0; k < letters.size(); k++)
                    newVec.push_back(vec[j] + letters[k]);
            
            // Replace the old result with the new one
            vec = newVec;
        }
        return vec;
    }
};