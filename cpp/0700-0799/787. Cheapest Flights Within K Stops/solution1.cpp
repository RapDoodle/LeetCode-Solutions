class Solution {
private:
    const int INF = INT_MAX/2;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Convert to adjacency list representation
        vector<vector<pair<int, int>>> graph(n);
        

        vector<vector<int>> dp(k+2, vector<int>(n, INF));
        dp[0][src] = 0;
        for (int t = 1; t <= k+1; ++t) {
            for (const auto& flight : flights)
                // flight[0]: src, flight[1]: dst, flight[2]: cost
                // Recurrence:
                //  dp[t][dst] = min(dp[t][dst], dp[t-1][src] + w(src, dst))
                // In other words, we are considering whether adding the `src` stop
                // as the last intermediate stop before reaching the destination 
                // lowers the overall cost.
                dp[t][flight[1]] = min(dp[t][flight[1]], dp[t-1][flight[0]] + flight[2]);
        }

        // The result is the minimum of dp[1, dst], dp[2, dst], ..., dp[k, dst]
        // We can't simply take dp[t, dst] because the value could be INF:
        // we may not be able to reach dst with exactly t stops. This is also true
        // for t in [1..k]
        int minCost = INF;
        for (int t = 1; t <= k+1; ++t)
            minCost = min(minCost, dp[t][dst]);
        return minCost == INF ? -1 : minCost;
    }
};