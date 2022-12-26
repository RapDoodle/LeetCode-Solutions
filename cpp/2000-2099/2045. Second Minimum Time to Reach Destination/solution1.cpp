class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Credit: https://www.youtube.com/watch?v=6CFkZP7gaYU
        // Convert to adjacency list representation
        vector<vector<int>> graph(n+1);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        // Key observation: The second minimum path can visit the same node
        // at most twice. So here, we store the count instead of a boolean
        vector<int> visited(n+1, 0);

        // Use BFS. The reason BFS can be applied is because the time it takes
        // to visit a node will not decrease when the node is visited from
        // another path with more hops.
        queue<pair<int, int>> q;
        vector<int> d(n+1, -1);  // Distance estimate
        q.emplace(make_pair(1, 0));  // The source

        while (!q.empty()) {
            auto [curr, t] = q.front();
            q.pop();

            if (!graph[curr].empty()) {
                // Calculate the time it takes to reach the next hop
                // All connected nodes will have the same cost estimate newT
                // Period 0, 2, 4, ... are for green lights
                // Period 1, 3, 5, ... are for red lights, must wait until the 
                //  period ends
                int period = t / change;
                int newT = (period % 2 == 0) ? t + time : (period+1)*change + time;

                // Visit neighboring nodes
                for (const auto& dst : graph[curr]) {
                    // Only push a node to the queue if it has not been visited
                    // twice. Only update if the estimated distance is increased.
                    // Note: the estimated distance is -1 initially.
                    if (visited[dst] < 2 && d[dst] < newT) {
                        d[dst] = newT;
                        visited[dst] += 1;
                        q.emplace(make_pair(dst, newT));

                        // Check whether we have reached the destination the 
                        // *second time*
                        if (dst == n && visited[dst] == 2)
                            return newT;
                    }
                }
            }
        }

        // Not found
        return -1;
    }
};