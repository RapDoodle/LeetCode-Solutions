class Solution {
public:
    /* Hash set */
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        long cnt = 0;
        for (const int& num : nums) {
            if (s.find(num) == s.end()) {
                // If it is a previously unseen 
                // element, we expect the count
                // be decremented twice by the other
                // two elements with the same value
                cnt += (long) num + num;
                s.insert(num);
            } else {
                cnt -= num;
            }
        }
        // The unique element's count was never
        // decremented after added to the count
        return cnt >> 1;
     }
};