class Solution {
public:
    /* Using an unordered_map */ 
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int y = target - x;
            auto it = mapping.find(y);
            if (it != mapping.end())
                return {it->second, i};
            mapping[x] = i;
        }
        return {};
    }
};

