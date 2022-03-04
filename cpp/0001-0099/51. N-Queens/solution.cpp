class Solution {
public:
    void backtrack(int r, vector<string>& board, int n, vector<bool>& cols, 
                   vector<bool>& posDiag, vector<bool>& negDiag, 
                   vector<vector<string>>& ans) {
        if (r == n)
            ans.push_back(board);
        
        // Find a position for the queen in the current row
        // Properties:
        //  1. Each row must have exactly one queen
        //  2. Each column must have exactly one queen
        //  3. Each diagonals must have exactly one queen
        //  4. Indexes along the positive diagonal satisfy:
        //      r + c = k, where k is a constant
        //  5. Indexes along the negative diagonal satisfy:
        //      r - c = k, where k is a constant
        for (int c = 0; c < n; ++c) {
            if (cols[c] || posDiag[r+c] || negDiag[r-c+n-1])
                continue;
            
            // Set the current states
            cols[c] = true;
            posDiag[r+c] = true;
            negDiag[r-c+n-1] = true;
            board[r][c] = 'Q';
            
            // Find the queen for the next row
            backtrack(r+1, board, n, cols, posDiag, negDiag, ans);
            
            // Reset the current states
            cols[c] = false;
            posDiag[r+c] = false;
            negDiag[r-c+n-1] = false;
            board[r][c] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false), posDiag(n, false), negDiag(n, false);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        // Start from the first row, the backtrack function will
        // recursively increment the row number
        backtrack(0, board, n, cols, posDiag, negDiag, ans);
        
        return ans;
    }
};