class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int provIndex) {
        // Mark the current city as visited
        visited[provIndex] = true;
        
        // Visit the current city's connected cities if the city
        // has not been visited
        for (int i = 0; i < isConnected.size(); ++i)
            if (isConnected[provIndex][i] && !visited[i])
                dfs(isConnected, visited, i);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
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