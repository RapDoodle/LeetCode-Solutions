const unordered_map<char, char> pairs = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        // Loop through every character in the string
        for (char c: s) {
            if (pairs.count(c) == 0) {
                // The current character does not exist form
                // the map's keys. In other words, an opening 
                // parenthesis. Push it to the stack
                stk.push(c);
            } else {
                // The current character forms the map's keys.
                // In other words, a closing parenthesis. Pop 
                // it from the stack
                if (!stk.empty() && stk.top() == pairs.at(c))
                    stk.pop();
                else
                    return false;
            }
        }
        
        // If the stack empty, all paris are valid
        return stk.empty();
    }
};