class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return findWays(expression, make_pair(0, expression.length() - 1));
    }
private:
    unordered_map<int, vector<int>> mem;
    
    vector<int> findWays(string& expression, pair<int, int> interval) {
        // NOT a good hash function. In the real-world, use a proper hash
        // function (like boost::hash).
        int hash_key = (interval.first << 16) ^ (interval.second << 4);
        if (mem.find(hash_key) != mem.end())
            return mem[hash_key];
        
        vector<int> ways;
        for (int i = interval.first; i <= interval.second; ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                const vector<int>& left = 
                    findWays(expression, make_pair(interval.first, i-1));
                const vector<int>& right = 
                    findWays(expression, make_pair(i+1, interval.second));
                
                // Apply operators on the Cartesian product of 
                // the two arrays
                for (const int& lv : left) {
                    for (const int& rv : right) {
                        int result;
                        if (c == '+')
                            result = lv + rv;
                        else if (c == '-')
                            result = lv - rv;
                        else
                            result = lv * rv;
                        ways.push_back(result);
                    }
                }
            }
        }
        
        // When the input string is a single number. E.g., "41"
        if (ways.empty())
            ways.push_back(stoi(expression.substr(
                interval.first, interval.second-interval.first+1)));
        
        mem[hash_key] = ways;
        
        return ways;
    }
};