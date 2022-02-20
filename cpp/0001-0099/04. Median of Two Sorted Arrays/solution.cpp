class Solution {
public:
    int floor_div(int a, int b) {
        int d = a / b;
        return d * b == a ? d : d - ((a < 0) ^ (b < 0));
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = total / 2;

        int aLo = 0, aHi = m - 1;
        while (true) {
            int aM = floor_div(aLo + aHi, 2);
            int bM = half - aM - 2;  // half - aM - 1 - 1

            int aL = (aM >= 0) ? nums1[aM] : INT_MIN;
            int aR = (aM + 1 < m) ? nums1[aM + 1] : INT_MAX;

            int bL = (bM >= 0) ? nums2[bM] : INT_MIN;
            int bR = (bM + 1 < n) ? nums2[bM + 1] : INT_MAX;

            if (aL <= bR && bL <= aR) {
                if (total % 2 == 0) {
                    // Even number, take the average
                    return (double)(max(aL, bL) + min(aR, bR)) / 2;
                } else {
                    // Odd number, take the min of aR and bR
                    return min(aR, bR);
                }
            } else if (aL > bR) {
                // Reduce the size of a
                aHi = aM - 1;
            } else {
                // Increase the size of a
                aLo = aM + 1;
            }
        }
        return 0;
    }
};