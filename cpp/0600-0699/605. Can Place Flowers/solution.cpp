class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for (int i = 0; i < len; ++i) {
            // Early-stopping
            if (n <= 0)
                break;
            
            if (flowerbed[i] == 0) {
                // If the current spot is empty, check whether
                // it is a potential spot for a flower
                // Handle edge cases, equivalent to add padding
                // to the 1D-array
                int left = i-1 >= 0 ? flowerbed[i-1] : 0;
                int right = i+1 < len ? flowerbed[i+1] : 0;
                if (left == 0 && right == 0) {
                    // If planting the flower in this spot does not
                    // violate the no-adjacent-flowers rule, reduce 
                    // the remaining flower count
                    --n;
                    
                    // Skip the next position as the next spot must
                    // voilates the no-adjacent rule
                    ++i;
                }
            }
        }
        
        // Check whether there are remaining flowers
        return n <= 0;
    }
};