class Solution {
public:
    /* BFS */
    int shortestPathLength(vector<vector<int>>& graph) {
        // High-level idea: Use BFS to visit neighbors ( 
        // visiting the same node is allowed). Start from
        // all vertices. Stop when all nodes are visited
        // for the first time (the one with the shortest
        // path).
        // Because all nodes visit the graph at the same 
        // time, we use a bit mask and associate it with 
        // each search.
        // Visited mask: Because there are only a maximum of
        // 12 nodes, a 16-bit word can be used to represent
        // the visited array.
        // Bit manipulations: 
        //  1. Access the i-th state:
        //      state=(1 << i) & mask
        //  2. Change the i-th state to 1: 
        //      mask = mask | (1 << i)
        int n = graph.size();
        queue<tuple<int, int, int>> q;

        // Use a cache to ensure a node is not visited 
        // again under the same visited mask. This avoids
        // duplicate search
        vector<vector<bool>> cache(n, vector<bool>(1 << n));
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            cache[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [u, visited, dist] = q.front();
            q.pop();

            // This avoids duplicate search if the current
            // node has been visited given the same visited
            // mask.
            if (visited == (1 << n) - 1)
                return dist;

            // Visit all adjacent neighbors, even if it is
            // a node v with the v-th bit in the visited mask
            //  set to 1.
            for (int v: graph[u]) {
                // Set the v-th position in the visited mask
                // to 1
                int new_visited = visited | (1 << v);
                if (!cache[v][new_visited]) {
                    q.emplace(v, new_visited, dist + 1);
                    cache[v][new_visited] = true;
                }
            }
        }

        return -1;
    }
};