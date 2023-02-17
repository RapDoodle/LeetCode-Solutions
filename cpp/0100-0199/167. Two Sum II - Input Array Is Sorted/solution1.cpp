class Solution {
public:
    /* Two pointers */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l+1, r+1};
            if (sum > target)
                // sum > target, need to reduce the sum
                --r;
            else
                // sum < target, need to increase the sum
                ++l;
        }
        
        // No matching solution (beyond the constraints)
        return {};
    }
};