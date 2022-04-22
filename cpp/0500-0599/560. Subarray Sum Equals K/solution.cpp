class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, psum = 0;
        
        // Key :prefix sum
        // Value: the occurrences of the prefix sum 
        unordered_map<int, int> m;
        
        // The initial value for the first match
        m[0] = 1;
        for (const int& num : nums) {
            psum += num;
            count += m[psum-k];
            ++m[psum];
        }
        return count;
    }
};