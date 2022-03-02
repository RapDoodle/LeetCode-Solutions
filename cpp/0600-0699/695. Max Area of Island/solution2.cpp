class Solution {
    const int directions[5] = {-1, 0, 1, 0, -1};
public:
    /* BFS */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), maxArea = 0;
        vector<vector<int>> visited(rows, vector<int>(cols));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Iterate through every i, j
                if (!visited[i][j]) {
                    int area = 0;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        // Make sure it is not:
                        //  1. Out of bound
                        //  2. Visited already
                        //  3. Not an island
                        if (p.first < 0 || p.second < 0 || p.first >= rows || p.second >= cols || 
                            visited[p.first][p.second] || !grid[p.first][p.second])
                            continue;
                        if (!visited[p.first][p.second]) {
                            visited[p.first][p.second] = 1;
                            ++area;
                            for (int k = 0; k < 4; ++k)
                                q.push(make_pair(p.first + directions[k], p.second + directions[k+1]));
                        }
                    }
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }
};