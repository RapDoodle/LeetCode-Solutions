class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // * Basic idea: Use a monotonic decreasing stack, where
        //   every element in the stack has a smaller value than
        //   the element below it. The top of the stack contains
        //   the lowest temperature in the current search range. 
        //   Whenever we find a day j such that
        //     temperatures[i] > temperatures[j], 
        //                              where j = stack.top()
        //   we can pop it from the stack, and mark the number of 
        //   days we have to wait on the j-th day to be difference 
        //   between the two days (j-i). Repeat this process until
        //   temperatures[i] <= temperatures[j]. (Remember: the
        //   stack is monotonically increasing as we pop elements
        //   away from the stack).
        // * To save memory, we only store the indices. We can
        //   retrieve the temperature using indices.
        stack<int> s;
        int n = temperatures.size();
        vector<int> days(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && 
                   temperatures[i] > temperatures[s.top()]) {
                days[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return days;
    }
};