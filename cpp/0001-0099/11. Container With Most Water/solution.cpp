class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int lPtr = 0, rPtr = height.size() - 1;
        while (lPtr < rPtr) {
            int area = min(height[lPtr], height[rPtr]) * (rPtr-lPtr);
            if (height[lPtr] >= height[rPtr])
                --rPtr;
            else
                ++lPtr;
            if (area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};