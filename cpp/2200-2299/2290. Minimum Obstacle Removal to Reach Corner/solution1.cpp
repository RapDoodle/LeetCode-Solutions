class Solution {
private:
    // The four directions: right, left, down, up
    static constexpr int dr[] = {0, 0, 1, -1};
    static constexpr int dc[] = {1, -1, 0, 0};

public:
    /* 0-1 BFS */
    int minimumObstacles(vector<vector<int>>& grid) {
        // High-level idea: Find the minimum path from source
        // to destination. For directions without obstacles, give
        // a weight of 0. Otherwise, the edge has a weight 
        // of 1, which corresponds to the need to remove an o
        // bstacle with a cost of 1. Because all weights
        // are either 0 or 1, we can use 0-1 BFS to solve the
        // problem.
        int m = grid.size(), n = grid[0].size(), len = m*n;
        vector<int> dist(len, INT_MAX);
        vector<bool> visited(len, false);
        deque<int> q;
        q.emplace_front(0);
        // If (0, 0) has an obstacle, we must remove it first
        dist[0] = grid[0][0] ? 1 : 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            visited[u] = true;
            int r = u / n, c = u % n;
            
            // Visit the four directions
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                int nu = nr*n + nc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Add 1 if grid[nr][nc] has an obstacle.
                    // Otherwise, add 0 to the cost estimate.
                    int nDist = dist[u] + (grid[nr][nc] ? 1 : 0);
                    if (nDist < dist[nu]) {
                        dist[nu] = nDist;
                        if (grid[nr][nc])
                            q.push_back(nu);
                        else
                            q.push_front(nu);
                    }
                }
            }
        }

        return dist[len-1];
    }
};