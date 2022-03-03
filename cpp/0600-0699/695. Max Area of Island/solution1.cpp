class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        // Base cases:
        //  1. Out of bound
        //  2. The grid is not an island
        //  3. The grid has been visited
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j])
            return 0;
        
        // Set the current grid as visited
        visited[i][j] = true;
        
        // Recursive case: look for islands in four directions
        return 1 + dfs(grid, visited, i+1, j)
                 + dfs(grid, visited, i-1, j) 
                 + dfs(grid, visited, i, j+1) 
                 + dfs(grid, visited, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), maxArea = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int area = dfs(grid, visited, i, j);
                if (area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }
};