class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Simulate stack behavior with a ..., stack!
        stack<int> stk;

        // i points at the pushed vector
        // j points at the popped vector
        // j only advances when popped[j] is part of a valid sequence
        int i = 0, j = 0, n = pushed.size();
        while (i < n) {
            stk.emplace(pushed[i++]);
            while (!stk.empty() && stk.top() == popped[j]) {
                ++j;
                stk.pop();
            }
        }

        return stk.empty();
    }
};