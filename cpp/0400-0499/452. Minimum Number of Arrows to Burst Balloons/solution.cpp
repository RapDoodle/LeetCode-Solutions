class Solution {
public:
    /* Greedy */
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        
        // Sort by the upper bound of the points
        sort(points.begin(), points.end(), [](vector<int>& x, vector<int>& y) {
            return x[1] < y[1];
        });
        
        // Reason for arrows = 1: at least one arrow is needed to cover 
        // the LAST group of ballons.
        // For example:
        //  Step 1:
        //        prevEnd
        //      |---| |---| |---|
        //          ^ i=1
        //          |
        //
        //  Step 2:
        //              prevEnd
        //      |---| |---| |---|
        //                ^ i=2
        //                |
        // 
        //  Step 3 (the loop has ended):
        //                   prevEnd
        //      |---| |---| |---|
        //                      ^ i=out of bound
        //                      |
        int prevEnd = points[0][1], arrows = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > prevEnd) {
                // Should shoot an arrow since it is out of the range
                // of the previous ballon. We have maximized the number
                // of ballons that can be shot with this arrow.
                //    prevEnd
                // |-----|       newEnd
                //       ^  |-------|
                //       |
                ++arrows;
                
                // Already shot the previous group of ballons
                prevEnd = points[i][1];
            }
            // Otherwise, it is still within the range
            //    prevEnd
            // |-----|
            //    |-------|
            //    ^
            //    |
        }
        
        return arrows;
    }
};