class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1, n = matrix[0].size()-1;
        
        // Because the first integer of each row is always greater
        // than the last integer of the previous row, we can
        // first find the row r where matrix[r][0] < target.
        // After determining the row r, we can perform a binary search
        // on that row to determine whether target is in the matrix.
        
        // Binary search on rows between [lo, hi]
        int lo = 0, hi = m, mid;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (matrix[mid][0] <= target && matrix[mid][n] >= target) {
                // Binary search on the current row
                int l = 0, r = n, mid2;
                while (l <= r) {
                    mid2 = (l + r) >> 1;
                    if (matrix[mid][mid2] == target)
                        return true;
                    else if (matrix[mid][mid2] > target)
                        // The value in the middle is greater than the target
                        r = mid2 - 1;
                    else
                        // The value in the middle is less than the target
                        l = mid2 + 1;
                }
                
                // Not found in the current row
                return false;
            } else if (matrix[mid][n] < target) {
                // The upper bound of the current row is less than target
                lo = mid + 1;
            } else {
                // The lower bound of the current row is greater than the target.
                // Or in other words, matrix[mid][0] > target
                hi = mid - 1;
            }
        }
        
        // No row has interval in the range containing the target
        return false;
    }
};