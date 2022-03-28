class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        
        // Start from the top-right:
        //  1. When the value is greater than target, move left
        //      The first row contains the lower bound of each 
        //      column. 
        //  2. When the value is less than target, move down
        //      The first column contains the lower bound of
        //      each row.
        int i = 0, j = n;
        while (i >= 0 && j >= 0 && i <= m && j <= n) {
            if (matrix[i][j] > target)
                --j;
            else if (matrix[i][j] < target)
                ++i;
            else
                return true;
        }
        
        return false;
    }
};