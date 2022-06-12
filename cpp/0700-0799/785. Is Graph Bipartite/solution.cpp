class Solution {
private:
    static constexpr short UNVISITED = 0;
    static constexpr short RED = 1;
    static constexpr short GREEN = -1;
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // In a bipartite graph, adjacent nodes should 
        // not have the same (or the same label)
        int n = graph.size();
        vector<short> color(n, UNVISITED);
        
        queue<int> q;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            // Skip the node if it has been visited
            if (color[i] != UNVISITED)
                continue;
            
            // Otherwise, start traversing on the graph
            // using BFS
            q.emplace(i);
            color[i] = RED;
            while (!q.empty()) {
                curr = q.front();
                q.pop();
                
                // Traverse the current node's adjacent
                // nodes. If adjacent nodes are labeled 
                for (const auto& neighbor : graph[curr]) {
                    if (color[neighbor] != UNVISITED) {
                        if (color[neighbor] == color[curr]) {
                            return false;
                        }
                    } else {
                        // If the current node have not 
                        // been visited, set its color
                        // to the current node's opposite
                        // Use -1 to flip the color, since
                        //  RED = 1 and GREEN = -1
                        color[neighbor] = -color[curr];
                        q.emplace(neighbor);
                    }
                }
            }
        }
        
        return true;
    }
};