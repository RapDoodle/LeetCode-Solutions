class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, n = prices.size(), minPrice = INT_MAX, maxProfit = INT_MIN;
        for (const int& price : prices) {
            // Maximum profit = prices[i] - prices[minT],
            // where prices[minT] points at the lowest price
            // given minT <= i
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price-minPrice);
        }
        return maxProfit;
    }
};