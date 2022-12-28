class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // High level idea: Walk from (0, 0) to (n-1, n-1) then 
        // walking back to (0, 0) can be thought of as going from
        // (0, 0) to (n-1, n-1) with two agents. Because it is
        // a grid, the Mahatten distance the two agents have to walk
        // from (0, 0) to (n-1, n-1) is the same. Thus, we have
        // the following key observation: given agent a's position
        // (a, b) and b's position (x, y): a + b = x + y.
        // Thus, y = a + b -x
        int n = grid.size();

        // Use a DP array to store (a, b, x, y). Because y can be
        // determined from a, b, and x, we only need 3 degree of 
        // freedom.
        vector<vector<vector<int>>> dp(n+1, 
            vector<vector<int>>(n+1, vector<int>(n+1, INT_MIN)));

        // Base case
        dp[1][1][1] = grid[0][0];

        // Recurrence:
        //  dp[a, b, x] = max(dp[a-1, b, x-1],  both goes down
        //                    dp[a, b-1, x-1],  a goes right, b goes down
        //                    dp[a-1, b, x],    a goes down, b goes right
        //                    dp[a, b-1, x])    both goes left
        //  where y = a + b -x
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                // Skip if it is an obstacle
                if (grid[a-1][b-1] == -1)
                    continue;

                for (int x = 1; x <= n; ++x) {
                    // For grid[0][0] = 1
                    if (a == 1 && b == 1 && x == 1)
                        continue;

                    int y = a + b - x;

                    // Skip invalid positions
                    if (y < 1 || y > n)
                        continue;
                    // cout << a << "," << b << "," << x << "," << y << endl;
                    // Skip if it is an obstacle
                    if (grid[x-1][y-1] == -1)
                        continue;

                    dp[a][b][x] = max(dp[a][b][x], dp[a-1][b][x-1]);
                    dp[a][b][x] = max(dp[a][b][x], dp[a][b-1][x-1]);
                    dp[a][b][x] = max(dp[a][b][x], dp[a-1][b][x]);
                    dp[a][b][x] = max(dp[a][b][x], dp[a][b-1][x]);

                    if (a == x && b == y)
                        dp[a][b][x] += grid[a-1][b-1];
                    else
                        dp[a][b][x] += grid[a-1][b-1] + grid[x-1][y-1];
                }
            }
        }

        return max(0, dp[n][n][n]);
    }
};