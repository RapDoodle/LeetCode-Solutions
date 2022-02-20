class Solution {
public:
    /* Two-pointers */
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        
        int l = 0, r = 1, maxProfit = 0;
        while (r < prices.size()) {
            int profit = prices[r] - prices[l];
            if (profit > 0) {
                maxProfit = max(profit, maxProfit);
            } else {
                // We found a point with an even lower price
                l = r;
            }
            r++;
        }
        
        return maxProfit;
    }
};