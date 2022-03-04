class Solution {
    vector<int> directions = {-1, 0, 1, 0, -1};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> blocks;
        
        // Grid
        //  0: Ocean
        //  1: Island
        //  2: Visited island
        
        // Find an island, the size does not matter.
        bool found = false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    // Found an island, find other blocks
                    // of the island using DFS
                    dfs(i, j, grid, blocks);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        // After the loop, every block in the first island 
        // found is marked as 2.
        
        int steps = 0;
        while (!blocks.empty()) {
            // For each iteration, pop all the blocks in the 
            // current queue. The BFS ensures we can find
            // every block within n+1 (where n is the variable 
            // `steps`) steps from the island border.
            size_t size = blocks.size();
            while (size--) {
                int x = blocks.front().first;
                int y = blocks.front().second;
                blocks.pop();
                
                // Visit neighboring blocks
                for (int i = 0; i < 4; ++i) {
                    int tx = x + directions[i];
                    int ty = y + directions[i+1];
                    
                    // Check for:
                    //  1. Out of bound
                    //  2. The block has been visited
                    if (tx < 0 || tx >= rows ||
                        ty < 0 || ty >= cols ||
                        grid[tx][ty] == 2)
                        continue;
                    
                    // If another island found, return
                    // the current step count, which is
                    // the shortest bridge possible.
                    if (grid[tx][ty] == 1)
                        return steps;
                    
                    // Mark the current block as visited
                    grid[tx][ty] = 2;
                    
                    // Push the current block to the queue
                    // so that its neighboring blocks
                    // will be visited when steps = steps+1
                    blocks.push(make_pair(tx, ty));
                }
            }
            
            // Increment the step count after every block 
            // within n+1 (where n is the variable `steps`) 
            // steps from the island border has been visited.
            ++steps;
        }
        
        return -1;
    }
private:
    void dfs(int i, int j, vector<vector<int>>& grid, 
             queue<pair<int, int>>& blocks) {
        // Check for:
        //  1. Out of bound
        //  2. The grid is not a part of the island
        if (i < 0 || i >= grid.size() || 
            j < 0 || j >= grid[0].size() || 
            grid[i][j] != 1)
            return;
        
        // Mark the block as visited and push it to the queue
        grid[i][j] = 2;
        blocks.push(make_pair(i, j));
        
        dfs(i+1, j, grid, blocks);
        dfs(i-1, j, grid, blocks);
        dfs(i, j+1, grid, blocks);
        dfs(i, j-1, grid, blocks);
    }
};