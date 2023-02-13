class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    /* Heap */
    MedianFinder() {}
    
    void addNum(int num) {
        // The idea is to use a max heap (can find 
        // the maximum in O(1)) to store the left 
        // half of the array and a min heap to store
        // the right half of the array. During insertions,
        // balance the size of the two heap:
        //  1. the size of the two heaps can be equal, or
        //  2. the max heap can have one more element than
        //     the min heap
        // | Max Heap | < | Min Heap |
        if (maxHeap.empty() || maxHeap.top() >= num) {
            maxHeap.emplace(num);
            if (maxHeap.size() - minHeap.size() == 2) {
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            minHeap.emplace(num);
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        // To calculate the median, if the two heaps are 
        // equal in size (even number of elements), 
        // return the mean of the maxHeap's maximum (left) 
        // and minHeap's minimum (right). If the maxHeap has
        // one more element than the minHeap (odd number of 
        // elements), return the middle one (maxHeap's max).
        return maxHeap.size() > minHeap.size() ? 
            maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */