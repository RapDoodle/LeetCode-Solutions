class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;
        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                const vector<int>& left = 
                    diffWaysToCompute(expression.substr(0, i));
                const vector<int>& right = 
                    diffWaysToCompute(expression.substr(i+1));
                
                // Apply operators on the Cartesian product of 
                // the two arrays
                for (const int& l : left) {
                    for (const int& r : right) {
                        int result;
                        if (c == '+')
                            result = l + r;
                        else if (c == '-')
                            result = l - r;
                        else
                            result = l * r;
                        ways.push_back(result);
                    }
                }
            }
        }
        
        // When the input string is a single number. E.g., "41"
        if (ways.empty())
            ways.push_back(stoi(expression));
        
        return ways;
        
        // Using memoization: solution2.cpp
    }
};