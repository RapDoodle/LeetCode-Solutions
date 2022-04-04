class NumMatrix {
private:
    vector<vector<int>> psum;
public:
    NumMatrix(vector<vector<int>>& matrix)
        : psum(matrix.size()+1, vector<int>(matrix[0].size()+1, 0)) {
        // Partial sum
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                psum[i][j] = matrix[i-1][j-1]   // Current position
                    + psum[i-1][j]              // psum to the top
                    + psum[i][j-1]              // psum to the left
                    - psum[i-1][j-1];           // The overlap region
        // The overlap region contains sum already partially counted 
        // in psum[i-1][j] and psum[i][j-1].
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Sum = A - B - C + D
        return psum[row2+1][col2+1] // Sum from matrix[0][0] to matrix[row2][col2] = A
            - psum[row1][col2+1]    // Sum from matrix[0][0] to matrix[row1-1][col2] = B
            - psum[row2+1][col1]    // Sum from matrix[0][0] to matrix[row2][col2-1] = C
            + psum[row1][col1];     // Sum from matrix[0][0] to matrix[row1-1][col1-1] = D
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */