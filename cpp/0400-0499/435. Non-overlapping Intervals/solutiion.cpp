class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return 0;
        
        // Sort the intervals according to the lower bound
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] < y[0];
        });
        
        // When two intervals overlap,
        // a    c    b        d
        // |    |    |        |
        // |    |----+--------|
        // |---------|
        // c is 
        int skip = 0, n = intervals.size(), prevEnd = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            // Check for overlapping
            if (intervals[i][0] < prevEnd) {
                // c < b, indicates overlapping
                ++skip;
                
                // Remove the interval whose upper bound is greater,
                // so that there is a smaller chance of overlapping
                // with other intervals (greedy)
                prevEnd = min(intervals[i][1], prevEnd);
            } else {
                // Not overlapped, simply move one step forward
                prevEnd = intervals[i][1];
            }
        }
        
        return skip;
    }
};