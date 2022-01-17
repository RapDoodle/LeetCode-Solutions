class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        // Loop through every character in the string
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // For all closing parentheses
                if (st.empty())
                    return false;
                char t = st.top();
                if (t == '(' && c == ')' || t == '[' && c == ']' || t == '{' && c == '}')
                    st.pop();
                else
                    return false;
            }
        }
        
        if (!st.empty())
            return false;
        return true;
    }
};