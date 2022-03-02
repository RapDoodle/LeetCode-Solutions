class Solution {
private:
    const int directions[5] = {-1, 0, 1, 0, -1};
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int i, int j) {
        if (reachable[i][j])
            return;
        
        reachable[i][j] = true;
        for (int d = 0; d < 4; ++d) {
            int x = i + directions[d], y = j + directions[d+1];
            
            // Check for:
            //  1. Within boundaries
            //  2. Water can flow in the reverse direction
            if (x >= 0 && y >= 0 && 
                x < heights.size() && 
                y < heights[0].size() &&
                heights[x][y] >= heights[i][j]) {
                dfs(heights, reachable, x, y);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty())
            return {};
        
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        // Iterate through the first row (from the pacific ocean)
        // and the last row (from the atlantic ocean)
        for (int i = 0; i < cols; ++i) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, rows - 1, i);
        }
        
        // Iterate through the first column (from the pacific ocean)
        // and the last column (from the atlantic ocean)
        for (int i = 0; i < rows; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, cols - 1);
        }
        
        // Find the regions that is both reachable from the pacific
        // and atlantic
        vector<vector<int>> ans;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
        
        return ans;
    }
};