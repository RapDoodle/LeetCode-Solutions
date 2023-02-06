class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        // Do a binary search on each row
        for (const auto& row : matrix) {
            // (Optional) Check if the row is in range
            if (row[0] > target || row[n-1] < target)
                continue;
            
            // Binary search
            int l = 0, r = n - 1, mid;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (row[mid] < target)
                    l = mid + 1;
                else if (row[mid] > target)
                    r = mid - 1;
                else
                    return true;
            }
        }

        // Not found
        return false;
    }
};