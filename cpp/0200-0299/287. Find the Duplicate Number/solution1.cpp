class Solution {
public:
    /* Floyd's Cycle Detection Algorithm */
    int findDuplicate(vector<int>& nums) {
        // Start from i = 0, the each edge connects 
        // i and (nums[i]-1)-th in a directed graph.
        int fast = 0, slow = 0;

        // Phase 1: The fast pointer moves 2 steps
        // at a time while the slow pointer moves 1
        // step at a time
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        // Phase 2: Reset one of the two pointers
        // to the beginning. Walk one step at a time
        // until they meet.
        fast = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Return one of the two
        return fast;
    }
};