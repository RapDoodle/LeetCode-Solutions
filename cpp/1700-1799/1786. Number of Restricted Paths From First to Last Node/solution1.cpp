class Solution {
private:
    const int MOD = 1e9 + 7;
    typedef pair<int, int> pi;

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // Convert to adjacency list representation
        vector<vector<pair<int, int>>> graph(n+1);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
            graph[edge[1]].emplace_back(make_pair(edge[0], edge[2]));
        }

        // Dijsktra's algorithm. Find the minimum cost from n to 
        // all other nodes.
        // Pair: (distance, nodeId)
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.emplace(0, n);
        vector<int> dist(n+1, INT_MAX);
        vector<int> numPaths(n+1, 0);  // The DP array

        // Base cases
        dist[n] = 0;
        numPaths[n] = 1;
        while (!q.empty()) {
            const auto [uDist, u] = q.top(); 
            q.pop();

            // Already had a better cost estimate
            if (uDist > dist[u]) 
                continue;

            // Terminate upon reaching the destination
            if (u == 1) 
                break;
            
            // Visit the connected neighbors
            for (const auto& [v, w] : graph[u]) {
                int newEstimate = uDist + w;
                if (newEstimate < dist[v]) {
                    // Found a better estimate
                    dist[v] = newEstimate;
                    q.emplace(newEstimate, v);
                }
                if (dist[u] < dist[v])
                    // Because dist[u] will not change afterwards,
                    // dist[v] is guaranteed to have a larger distance.
                    numPaths[v] = (numPaths[v] + numPaths[u]) % MOD;
            }
        }

        // return numPaths[n];
        return numPaths[1];
    }
};