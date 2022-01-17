class Solution {
public:
    void backtrack(int numOpen, int numClose, const int& n, string& s, vector<string>& res) {
        // Base case: generated n-pairs of open and close parenthesis
        if (numOpen == numClose && numOpen == n) {
            res.push_back(s);
            return;
        }
        
        // Recursive case:
        // 1. Add an open parenthesis when numOpen < n.
        //    E.g., ((, numOpen = 2, n = 3
        if (numOpen < n) {
            s.push_back('(');
            backtrack(numOpen + 1, numClose, n, s, res);
            s.pop_back();  // After DFS, remove the used part
        }
        
        // 2. Add an close parenthesis if numOpen > numClose.
        //    E.g., ((), numOpen = 2, numClose = 1. Adding one more
        //    closing parenthsis makes the string valid
        if (numOpen > numClose) {
            s.push_back(')');
            backtrack(numOpen, numClose + 1, n, s, res);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        // Because backtracking is a depth-first-search algorithm, 
        // only one string is needed, as long as we remove the used
        // part.
        string s;
        
        // Start backtracking
        backtrack(0, 0, n, s, ans);
        
        return ans;
    }
};