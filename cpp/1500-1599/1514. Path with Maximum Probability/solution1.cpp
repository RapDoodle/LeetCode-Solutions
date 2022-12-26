class Solution {
public:
    /* Dijsktra's Algorithm */
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Convert to adjacency list representation
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            double logProb = -log2(succProb[i]);
            graph[edges[i][0]].emplace_back(make_pair(edges[i][1], logProb));
            graph[edges[i][1]].emplace_back(make_pair(edges[i][0], logProb));
        }

        // Run the modified Dijsktra's algorithm
        vector<double> D(n, DBL_MAX);
        vector<bool> finalized(n, false);
        D[start] = 0;
        
        for (int _ = 0; _ < n; ++_) {
            // Look for the node with the smallest estimate among 
            // unfinalized nodes
            int minNodeIdx = -1;
            double minNodeVal = DBL_MAX;
            for (int i = 0; i < n; ++i) {
                if (!finalized[i] && minNodeVal >= D[i]) {
                    minNodeIdx = i;
                    minNodeVal = D[i];
                }
            }
            
            // Finalize the node
            finalized[minNodeIdx] = true;

            // Check if the current node is not reachable from source
            // (indicated by having DBL_MAX)
            if (abs(minNodeVal - DBL_MAX) < 1e-5)
                continue;

            // Visit all its neighbors
            for (const auto& edge : graph[minNodeIdx]) {
                // minNodeIdx: current node
                // edge.first: destination node
                // edge.second: edge cost
                double estimate = D[minNodeIdx] + edge.second;
                if (D[edge.first] > estimate)
                    // A shorter path is found, update the estimate
                    D[edge.first] = estimate;
            }
        }
        
        return (abs(D[end] - DBL_MAX) < 1e-5) ? 0.0 : pow(0.5, D[end]);
    }
};