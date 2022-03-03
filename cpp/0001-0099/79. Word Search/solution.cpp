class Solution {
public:
    bool dfs(int i, int j, int strSize, vector<vector<bool>>& visited, 
             const vector<vector<char>>& board, const string& word) {
        if (strSize == word.length())
            return true;
        
        // Check for the following invalid cases:
        //  1. Out of bound
        //  2. The position has been visited
        //  3. The position does not have the correct
        //     corresponding character
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size() ||
            visited[i][j] || 
            word[strSize] != board[i][j])
            return false;
        
        // Mark the current position as visited
        visited[i][j] = true;
        
        // Recursively visit sorrounding nodes
        int res = (dfs(i+1, j, strSize+1, visited, board, word) ||
                   dfs(i-1, j, strSize+1, visited, board, word) ||
                   dfs(i, j+1, strSize+1, visited, board, word) ||
                   dfs(i, j-1, strSize+1, visited, board, word));
        
        // Unset the visited mark
        visited[i][j] = false;
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<char> str;
        
        // NOTE: Even though using sets could save memory, the 
        // performance deteriorates (causes time-limit-exceeded
        // error)
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Check for every position. Stop until a valid path is found
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(i, j, 0, visited, board, word))
                    return true;
        
        return false;
    }
};