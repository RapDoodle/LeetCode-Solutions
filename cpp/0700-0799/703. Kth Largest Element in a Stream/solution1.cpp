class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    /* Min heap */
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for (const int& num : nums)
            add(num);
    }
    
    int add(int val) {
        if (pq.size() == k) {
            // The min heap is full. Need to
            // decide whether or not val should
            // be added.
            // E.g., pq contains [1,2,3] and k = 3.
            //  add(0): 0 does not affect the 3rd 
            //    largest value
            //  add(2): 2 becomes the 2nd or 3rd 
            //    largest value, remove 1.
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        } else {
            // The min heap is not full yet
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */