class Solution {
private:
    typedef pair<double, int> pi;

public:
    /* Dijkstra's Algorithm */
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Convert to adjacency list representation
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            double logProb = -log2(succProb[i]);
            graph[edges[i][0]].emplace_back(make_pair(edges[i][1], logProb));
            graph[edges[i][1]].emplace_back(make_pair(edges[i][0], logProb));
        }

        // Run the modified Dijkstra's algorithm
        priority_queue<pi, vector<pi>, greater<pi>> q;
        vector<double> dist(n, DBL_MAX);
        vector<bool> finalized(n, false);
        dist[start] = 0;
        q.emplace(0.0, start);
        
        while (!q.empty()) {
            // Look for the node with the smallest estimate among 
            // unfinalized nodes
            const auto [uDist, u] = q.top();
            q.pop();
            
            // Avoid infinite loop
            if (finalized[u])
                continue;
            
            // Finalize the node
            finalized[u] = true;

            // Check if the current node is not reachable from source
            // (indicated by having DBL_MAX)
            if (abs(uDist - DBL_MAX) < 1e-5)
                continue;

            // Visit all its neighbors
            for (const auto& [v, w] : graph[u]) {
                // u: current node
                // v: destination node
                // w: edge cost
                double estimate = dist[u] + w;
                if (dist[v] > estimate)
                    // A shorter path is found, update the estimate
                    dist[v] = estimate;
                    q.emplace(estimate, v);
            }
        }
        
        return (abs(dist[end] - DBL_MAX) < 1e-5) ? 0.0 : pow(0.5, dist[end]);
    }
};