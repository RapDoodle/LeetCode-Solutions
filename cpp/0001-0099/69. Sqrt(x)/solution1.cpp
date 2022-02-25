class Solution {
public:
    /* Binary search */
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        
        int l = 1, r = x, mid;
        while (l <= r) {
            // Avoid overflow (the upper bound is
            // 2^31 - 1). The following code is 
            // equivalent to (l + r) / 2:
            //   l + (r-1) / 2
            // = (2l - l + r) / 2
            // = (l + r) / 2
            mid = l + (r - l) / 2;
            
            // Use division instead of multiplication 
            // to avoid overflow:
            // mid^2 = x, divide both side by mid,
            // we get mid = x / a
            int temp = x / mid;
            if (temp == mid) {
                return mid;
            } else if (mid > temp) {
                // Result too big, search from the left half
                r = mid - 1;
            } else {
                // Result to small, search from the right half
                l = mid + 1;
            }
        }
        
        // r*r < x
        return r;
    }
};