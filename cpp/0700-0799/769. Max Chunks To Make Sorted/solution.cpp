class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, curMax = 0;
        for (int i = 0; i < arr.size(); ++i) {
            // When the current maximum is greater than the 
            // index, it indicates that the current value must 
            // be added to the current chunk, the chunk count 
            // is unchanged.
            // We add 1 to the chunk count when 
            //  (1) The current maximum matches the index, meaning
            //      the current position does not need to be sorted
            //      (forms a chunk with itself). For example,
            //          arr = [0,1,2,3,4], i = 1, 
            //          [1] can form a chunk with itself.
            //  (2) The interval between the last sorted position 
            //      and the i-th position can be arranged into a
            //      chunk (to be sorted). For example,
            //          arr = [1,0,2,3,4], i = 1, 
            //          [1,0] need to be sorted.
            curMax = max(curMax, arr[i]);
            if (curMax == i)
                ++chunks;
        }
        return chunks;
    }
};