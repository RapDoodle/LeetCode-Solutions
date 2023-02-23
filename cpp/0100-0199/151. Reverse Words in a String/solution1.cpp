class Solution {
public:
    /* In place edit */
    string reverseWords(string s) {
        // Reverse the string
        int n = s.length(), i = 0, j = n - 1;
        while (i < j)
            swap(s[i++], s[j--]);
        // "  the sky " now becomes " yks eht  "

        // Reverse each word
        i = 0, j = 0;
        int k = 0;
        while (i < n) {
            // Find the word's starting index
            if (s[i] == ' ') {
                ++i;
            }

            // Find the word's ending index
            j = i + 1;
            while (j < n && s[j] != ' ')
                ++j;
            
            // j should now be pointing at the index
            // after the word or the end of the string.
            // i can continue at this position
            k = j;

            // Go back to the end of the word
            --j;

            while (i <= j)
                swap(s[i++], s[j--]);
            
            i = k;
        }

        // Remove additional empty spaces
        // points at the original string
        i = 0;

        // points at the output string (without 
        // additional spaces)
        k = 0;
        while (i < n) {
            while (s[i] == ' ')
                ++i;
            // Insert an ' ' if it is not the 
            // beginning of the string
            if (k > 0 && i < n)
                s[k++] = ' ';
            while (i < n && s[i] != ' ')
                s[k++] = s[i++];
        }

        s.erase(s.begin() + k, s.end());
        return s;
    }
};