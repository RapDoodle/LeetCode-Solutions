class Solution {
private:
    const int INF = INT_MAX / 2;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = 1;
            dist[edge[1]][edge[0]] = 1;
        }

        // Floyd-Warshall all source shortest path algorithm
        for (int k = 0; k < n; ++k)
            for (int u = 0; u < n; ++u)
                for (int v = 0; v < n; ++v)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

        // Sum every node's distance to all other nodes
        vector<int> distSum(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j && dist[i][j] != INF)
                    distSum[i] += dist[i][j];

        return distSum;
    }
};