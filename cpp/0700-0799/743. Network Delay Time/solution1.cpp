class Solution {
public:
    /* Dijkstra's algorithm */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (const auto& edge : times) {
            graph[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        }

        // Dijkstra's algorithm
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        vector<bool> visited(n+1, false);
        int maxCost = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            // Find the node with the minimum cost estimate
            int curr = -1, currCost = INT_MAX;
            for (int j = 1; j <= n; ++j) {
                if (!visited[j] && dist[j] < currCost) {
                    currCost = dist[j];
                    curr = j;
                }
            }

            // If the node is not reachable, no node can lower
            // its estimate, and it has an estimate if INT_MAX
            if (currCost == INT_MAX)
                return -1;

            // Mark the current node as visited
            visited[curr] = true;

            // Update the maximum cost
            maxCost = max(maxCost, currCost);

            // Update node neighbors' cost estimate
            for (const auto& [dst, cost] : graph[curr]) {
                dist[dst] = min(dist[dst], currCost + cost);
            }
        }

        // The minimuim time equals the maximum cost
        return maxCost;
    }
};