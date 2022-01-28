class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        auto i = nums.begin(), j = i + 1;
        while (i != nums.end() && j != nums.end()) {
            if (*i != *j) {
                i++;
                j++;
            } else {
                while (j != nums.end() && *i == *j)
                    j++;
                nums.erase(i + 1, j);
                i++;
                j = i + 1;
            }
        }
        
        return nums.size();
    }
};