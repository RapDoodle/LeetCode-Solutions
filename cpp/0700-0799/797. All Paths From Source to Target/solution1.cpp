class Solution {
private:
    /* DFS */
    void dfs(int i, vector<int>& currPath, 
             vector<vector<int>>& paths, 
             const vector<vector<int>>& graph) {
        currPath.emplace_back(i);
        if (i == graph.size() - 1) {
            // Reached the target
            paths.emplace_back(currPath);
        } else {
            // Visit every connected node
            for (int j = 0; j < graph[i].size(); ++j)
                dfs(graph[i][j], currPath, paths, graph);
        }
        currPath.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currPath;
        vector<vector<int>> paths;
        dfs(0, currPath, paths, graph);
        return paths;
    }
};