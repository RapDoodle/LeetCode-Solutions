class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int provIndex) {
        // Mark the current city as visited
        visited[provIndex] = 1;
        
        // Visit the current city's connected cities
        for (int i = 0; i < isConnected.size(); ++i)
            if (isConnected[provIndex][i] && !visited[i])
                dfs(isConnected, visited, i);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int provCount = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ++provCount;
            }
        }
        return provCount;
    }
};