class Solution {
private:
    const int INF = INT_MAX / 2;
public:
    /* Dynamic Programming */
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        // Dynamic programming
        // dp[t][i]: The minimum cost to reach i within time t
        vector<vector<int>> dp(maxTime+1, vector(n, INF));

        // The initial cost is the cost passing the source
        dp[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; ++t) {
            for (const auto& edge : edges) {
                // edge[0]: u, edge[1]: v, edge[2]: pathTimeCost
                // In other words, when t >= pathTimeCost
                //  1. to reach v, use u as the last intermediate stop if it lowers the cost:
                //    dp[t, v] = min(dp[t, v], dp[t-pathTimeCost, u] + passingFees[u])
                //  2. to reach u, use v as the last intermediate stop if it lowers the cost:
                //    dp[t, u] = min(dp[t, u], dp[t-pathTimeCost, v] + passingFees[v])
                if (t >= edge[2]) {
                    dp[t][edge[1]] = min(dp[t][edge[1]], dp[t-edge[2]][edge[0]] + passingFees[edge[1]]);
                    dp[t][edge[0]] = min(dp[t][edge[0]], dp[t-edge[2]][edge[1]] + passingFees[edge[0]]);
                }
            }
        }
        
        // The result is the minimum of dp[1, dst], dp[2, dst], ..., dp[k, dst]
        // We can't simply take dp[t, dst] because the value could be INF:
        // we may not be able to reach dst with exactly t stops. This is also true
        // for t in [1..k]
        int minCost = INF;
        for (int t = 0; t <= maxTime; ++t)
            minCost = min(minCost, dp[t][n-1]);

        return minCost == INF ? -1 : minCost;
    }
};