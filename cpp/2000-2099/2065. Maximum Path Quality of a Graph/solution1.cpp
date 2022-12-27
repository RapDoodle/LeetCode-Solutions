class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();

        // Convert to adjacency list representation
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
            graph[edge[1]].emplace_back(make_pair(edge[0], edge[2]));
        }

        int maxQuality = 0;
        vector<bool> visited(n, false);
        visited[0] = true;

        // Run DFS to find all possible paths
        function<void(int, int, int)> dfs = [&](int u, int time, int currQuality) {
            // Mark the end of one possible valid path. 
            // Continue searching afterwards
            if (u == 0)
                maxQuality = max(maxQuality, currQuality);
            
            // Visit neighboring nodes
            for (const auto& [v, cost]: graph[u]) {
                if (time >= cost) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dfs(v, time-cost, currQuality + values[v]);
                        visited[v] = false;
                    } else {
                        dfs(v, time-cost, currQuality);
                    }
                }
            }
        };
        
        dfs(0, maxTime, values[0]);
        return maxQuality;
    }
};