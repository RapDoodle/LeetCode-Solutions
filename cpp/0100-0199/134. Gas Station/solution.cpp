class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Credit: https://youtu.be/lJwbPZGo05A
        // Initial check on whether it is even possible
        // to finishthe loop
        if (accumulate(gas.begin(), gas.end(), 0) < 
            accumulate(cost.begin(), cost.end(), 0))
            return -1;
        
        // Guaranteed that finishing the loop is possible
        // Use greedy to look for the starting position
        int total = 0, startPos = 0;
        for (int i = 0; i < gas.size(); ++i) {
            // The cost at each step
            total += gas[i] - cost[i];
            if (total < 0) {
                // If the current position dips below 0,
                // the position is not suitable for being
                // the starting position
                total = 0;
                // Start from the next position
                startPos = i + 1;
            }
        }
        // Notice that going back to the first index is not
        // needed because we know that there's a unique
        // solution.
        
        return startPos;
    }
};