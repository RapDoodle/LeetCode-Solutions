class Solution {
public:
    /* Boyer-Moore majority voting algorithm */
    int majorityElement(vector<int>& nums) {
        // We can use the algorithm only when there exists
        // a majority element
        int cnt = 1, val = -1;
        for (const int& num : nums) {
            if (num == val) {
                ++cnt;
            } else {
                // Because we know the majority element x
                // consists of at least 50% of the array,
                // x will eventually replace other numbers 
                // when the count for other numbers are 
                // decremented to 0. 
                // If it is already in val, no number can
                // replace val.
                if (--cnt == 0) {
                    cnt = 1;
                    val = num;
                }
            }
        }
        return val;
    }
    /* References:
     *  1. https://en.wikipedia.org/wiki/Boyer-Moore_majority_vote_algorithm
     *  2. https://www.youtube.com/watch?v=7pnhv842keE (NeetCode)
     */
};