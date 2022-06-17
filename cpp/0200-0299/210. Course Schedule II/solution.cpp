class Solution {
private:
    static constexpr short UNVISITED = 0;
    static constexpr short VISITING = 1;
    static constexpr short VISITED = 2;
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Use topological sort
        // Convert into an adjacency list
        vector<vector<int>> graph(numCourses);
        for (const auto& prerequisite : prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);
        
        // Vertex status
        vector<char> visited(numCourses, false);
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (!dfs(i, graph, visited, ans))
                    return {};
            }
        }
        
        return ans;
    }
    
private:
    bool dfs(int u, const vector<vector<int>>& graph, 
             vector<char>& visited, vector<int>& ans) {
        // Mark the current vertex as visiting
        visited[u] = VISITING;
        
        // Check the vertex's adjacent vertices
        for (const auto& i : graph[u]) {
            if (visited[i] == VISITING) {
                // A loop is detected
                return false;
            } else if (visited[i] == UNVISITED && u != i) {
                // The vertex has not been visited, visit the node.
                // Immediately exit the recursion as soon as a loop
                // is detected.
                if (!dfs(i, graph, visited, ans)) {
                    return false;
                }
            }
        }
        
        // Mark the current state as visited
        visited[u] = VISITED;
        
        // Append the result
        ans.emplace_back(u);
        
        return true;
    }
};