class Solution {
public:
    /* Stack */
    string reverseWords(string s) {
        stack<char> stk;
        int i = 0, j = 0, k = 0, n = s.length();
        while (i < n) {
            // Find the word's starting index
            if (s[i] == ' ')
                ++i;
            
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

            // Push the word in reverse order
            while (j >= i)
                stk.emplace(s[j--]);
            
            i = k;

            stk.emplace(' ');
        }

        if (!stk.empty() && stk.top() == ' ')
            stk.pop();
        
        string out;
        while (!stk.empty()) {
            out.push_back(stk.top());
            stk.pop();
        }

        return out;
    }
};