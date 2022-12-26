class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX/2));
        for (const auto& edge : edges) {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall all source shortest path algorithm
        for (int k = 0; k < n; ++k)
            for (int u = 0; u < n; ++u)
                for (int v = 0; v < n; ++v)
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);

        // Find the city with the minimum number of neighbors
        int cityId = -1, minCount = INT_MAX;
        for (int u = 0; u < n; ++u) {
            // Count the number of cities within the given threshold
            int count = 0;
            for (int v = 0; v < n; ++v)
                if (u != v && dp[u][v] <= distanceThreshold)
                    ++count;
            if (count <= minCount) {
                cityId = u;
                minCount = count;
            }
        }

        return cityId;
    }
};