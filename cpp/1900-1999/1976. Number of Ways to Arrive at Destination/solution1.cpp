class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    /* Dijsktra's Algorithm + DP */
    int countPaths(int n, vector<vector<int>>& roads) {
        // Convert to adjacency list representation
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            graph[road[0]].emplace_back(make_pair(road[1], road[2]));
            graph[road[1]].emplace_back(make_pair(road[0], road[2]));
        }

        // Keep track of the number of ways to reach a node
        vector<int> ways(n, 0);

        // Run the modified Dijsktra's algorithm
        vector<long> D(n, LONG_MAX);
        vector<bool> finalized(n, false);
        ways[0] = 1;
        D[0] = 0;
        
        for (int _ = 0; _ < n; ++_) {
            // Look for the node with the smallest estimate among 
            // unfinalized nodes
            int minNodeIdx = -1;
            long minNodeVal = LONG_MAX;
            for (int i = 0; i < n; ++i) {
                if (!finalized[i] && minNodeVal > D[i]) {
                    minNodeIdx = i;
                    minNodeVal = D[i];
                }
            }
            
            // Finalize the node
            finalized[minNodeIdx] = true;

            // Visit all its neighbors
            for (const auto& edge : graph[minNodeIdx]) {
                // minNodeIdx: current node
                // edge.first: destination node
                // edge.second: edge cost
                long estimate = D[minNodeIdx] + edge.second;
                if (D[edge.first] > estimate) {
                    // A shorter path is found, update the estimate
                    // and restart the counter
                    D[edge.first] = estimate;
                    ways[edge.first] = ways[minNodeIdx];
                } else if (D[edge.first] == estimate) {
                    // The path is already the shortest path, add the 
                    // number of ways minNodeIdx can be reached to 
                    // the destination node's counter
                    ways[edge.first] = (ways[edge.first] + ways[minNodeIdx]) % MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};