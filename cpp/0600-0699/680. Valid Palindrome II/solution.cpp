class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        // Invoke the helper method, with the recursive
        // flag set to true. The flag is set to false
        // in subsequent recursive calls, ensuring at 
        // most one character is deleted if needed.
        return isPalindrome(s, i, j, true);
    }
    
    bool isPalindrome(string& s, int i, int j, bool recursive) {
        while (i <= j) {
            if (s[i] != s[j]) {
                // When recursive is allowed, check the two possibilities:
                // remove s[i] or s[j] 
                return recursive ? 
                    isPalindrome(s, i+1, j, false) || isPalindrome(s, i, j-1, false) : false;
            }
            ++i;
            --j;
        }
        return true;
    }
};