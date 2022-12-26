class Solution {
private:
    static constexpr int dx[] = {-1, 1, 0, 0};
    static constexpr int dy[] = {0, 0, -1, 1};

    void dfs(const int i, const int j, int pathLen, vector<bool>& visited, 
        int& pathCount, vector<vector<int>>& grid, const int m, const int n, 
        const int di, const int dj, const int emptyCount) {
        // Check whether it has reached the destination
        if (i == di && j == dj) {
            // Reason for -1: the ending square should not be counted 
            // as an empty sqaure.
            if (pathLen-1 == emptyCount)
                pathCount++;
            return;
        }
        
        // Mark the current node as visited
        // Each node is identified with an unique id.
        visited[i*n + j] = true;

        // Visit all four directions
        for (int a = 0; a < 4; ++a) {
            int currI = i+dx[a], currJ = j+dy[a];

            // Check for out of bound
            if (currI < 0 || currJ < 0 || currI >= m || currJ >= n)
                continue;
            
            // Check whether it has been visited
            if (visited[currI*n + currJ])
                continue;

            // Check whether the new position is an obstacle
            if (grid[currI][currJ] == -1)
                continue;
            
            // Make the recursive call
            dfs(currI, currJ, pathLen+1, visited, pathCount, 
                grid, m, n, di, dj, emptyCount);
        }
        
        // Unset the visited status
        visited[i*n + j] = false;
        
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Find the source and destination
        int si = -1, sj = -1, di = -1, dj = -1, emptyCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++emptyCount;
                } else if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 2) {
                    di = i;
                    dj = j;
                }
            }
        }

        vector<bool> visited(m*n, false);
        int pathCount = 0;

        // The starting position does not count as an empty square. So the 
        // path length is 0 initially.
        dfs(si, sj, 0, visited, pathCount, grid, m, n, di, dj, emptyCount);
        return pathCount;
    }
};