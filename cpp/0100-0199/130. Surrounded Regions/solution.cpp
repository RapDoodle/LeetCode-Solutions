class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Basic idea: Instead of looking for surrounded regions,
        // look for unsurrounded regions which are on the edge
        // of the board
        const int rows = board.size(), cols = board[0].size();
        
        // Check for unsurrounded regions by searching on the
        // board's edge:
        // Check the first and last row
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O')
                dfs(0, c, board);
            if (board[rows-1][c] == 'O')
                dfs(rows-1, c, board);
        }
        // Check the first column
        for (int r = 1; r < rows-1; ++r) {
            if (board[r][0] == 'O')
                dfs(r, 0, board);
            if (board[r][cols-1] == 'O')
                dfs(r, cols-1, board);
        }
        
        // After the two loops, all unsurrounded regions will
        // be marked as #. For example
        //  ["X","X","X","X"],
        //  ["X","X","O","X"],
        //  ["X","O","X","X"],
        //  ["X","O","X","X"]
        // will be marked as
        //  ["X","X","X","X"],
        //  ["X","X","O","X"],
        //  ["X","#","X","X"],
        //  ["X","#","X","X"]
        
        // Iterate through the board. Any position that is still
        // marked as 'O' means it can be surrounded. Mark it
        // as 'X'. At the same time, mark all '#' as 'O'.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(int i, int j, vector<vector<char>>& board) {
        // Check for:
        //  1. Out of bound
        //  2. Not an 'X'
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] != 'O')
            return;
        
        // Mark the region as not surrounded, will be 
        // replaced with 'O' later
        board[i][j] = '#';
        
        // When board[i][j] == 'O', use DFS to check
        // surrounding blocks
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }
};