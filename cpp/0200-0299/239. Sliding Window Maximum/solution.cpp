class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // The deque stores the indexes
        deque<int> dq;
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            // To ensure the deque stores the indexes whose
            // values are in decreasing order (the last element 
            // in the deque is the smallest number in the interval, 
            // and the left-most element is the largest):
            //  1. from the right of the deque, pop away any 
            //     value less than the current value
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            //  2. from the left of the deque, pop away the 
            //     out-of-bound number (if the number is not 
            //     popped in step 1)
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
            // Push the current value to the deque (the smallest
            // in the interval)
            dq.push_back(i);
            
            // After reaching the window size, add the front (the 
            // largest value i nthe interval to the result)
            if (i >= k - 1)
                ans[i-k+1] = nums[dq.front()];
        }
        return ans;
    }
};