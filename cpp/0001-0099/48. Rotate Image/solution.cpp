class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1, temp;
        for (int i = 0; i <= n/2; ++i) {
            for (int j = i; j < n-i; ++j) {
                // Rotate (i, j), (j, n-i), (n-i, n-j), (n-j, i) 
                // clockwise.
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = temp;
            }
        }
    }
};