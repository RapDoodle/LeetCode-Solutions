class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        queue<int> q;
        int provCount = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int j = q.front();
                    q.pop();
                    visited[j] = 1;
                    for (int k = 0; k < isConnected.size(); ++k)
                        if (isConnected[j][k] && !visited[k])
                            q.push(k);
                }
                ++provCount;
            }
        }
        return provCount;
    }
};