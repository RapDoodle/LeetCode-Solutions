class Solution {
private:
    // The four directions: right, left, down, up
    static constexpr int dr[] = {0, 0, 1, -1};
    static constexpr int dc[] = {1, -1, 0, 0};

public:
    /* 0-1 BFS */
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), len = m*n;
        vector<int> dist(len, INT_MAX);
        vector<bool> visited(len, false);

        // High-level idea: Find the minimum path from source
        // to destination. For specified directions, give
        // a weight of 0. Otherwise, the edge has a weight 
        // of 1, which corresponds to the need of change
        // the direction with a cost of 1. Because all weights
        // are either 0 or 1, we can use 0-1 BFS to solve the
        // problem
        deque<int> q;
        q.emplace_front(0);
        dist[0] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            visited[u] = true;
            int r = u / n, c = u % n;
            
            // Visit the four directions
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                int nu = nr*n + nc;
                // Add 0 if grid[r][c] has the same direction.
                // Otherwise, add 1 to the cost estimate
                // See the definition of the four directions
                // at the top.
                bool sameDir = (grid[r][c] == i+1);
                int nDist = dist[u] + (sameDir ? 0 : 1);
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && nDist < dist[nu]) {
                    dist[nu] = nDist;
                    if (sameDir)
                        q.push_front(nu);
                    else
                        q.push_back(nu);
                }
            }
        }

        return dist[len-1];
    }
};