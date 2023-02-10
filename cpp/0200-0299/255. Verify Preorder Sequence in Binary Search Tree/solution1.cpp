class Solution {
public:
    /* Monotonic stack */
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        // currMax stores the largest value popped so far
        int currPoppedMax = INT_MIN, n = preorder.size();
        for (int i = 0; i < n; ++i) {
            // Stack elements are only popped when a larger
            // value occurs. So whenever we encounter a value
            // smaller than the largest value popped so far, 
            // the know the number should appear somewhere 
            // to the left of the current node, not to the 
            // right. 
            if (preorder[i] < currPoppedMax)
                return false;
            while (!stk.empty() && stk.top() < preorder[i]) {
                currPoppedMax = max(currPoppedMax, stk.top());
                stk.pop();
            }
            stk.emplace(preorder[i]);
        }
        return true;
    }
};