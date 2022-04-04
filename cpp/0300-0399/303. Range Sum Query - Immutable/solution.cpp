class NumArray {
private:
    vector<int> psum;
public:
    NumArray(vector<int>& nums) : psum(nums.size() + 1, 0) {
        // Calculate the running total for the numbers in nums
        partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
    }
    
    int sumRange(int left, int right) {
        // Explanation for the choice of indices:
        //  1. Why use psum[right+1] instead of psum[right]?
        //      Because psum has a size of nums.size()+1 and
        //      the first element in the array is 0.
        //  2. Then why not use psum[left+1]?
        //      Because using an index of left+1 excludes the
        //      range's lower bound.
        return psum[right+1] - psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */