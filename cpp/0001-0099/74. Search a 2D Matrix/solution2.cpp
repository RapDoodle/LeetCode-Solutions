class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // Equivalent to binary search on the flatteded 1D-array
        int lo = 0, hi = m*n - 1, mid, x;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            x = matrix[mid / n][mid % n];
            if (x == target)
                return true;
            else if (x < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        // Not found
        return false;
    }
};