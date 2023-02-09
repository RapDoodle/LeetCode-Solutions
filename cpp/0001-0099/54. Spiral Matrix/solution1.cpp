class Solution {
private:
    static constexpr int dx[] = {1, 0, -1, 0};
    static constexpr int dy[] = {0, 1, 0, -1};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        vector<int> order;
        order.reserve(matrix.size()*matrix[0].size());
        int dir = 0, x = 0, y = 0;
        int minX = 0, maxX = matrix[0].size()-1, minY = 0, maxY = matrix.size()-1;
        while (minX <= maxX && minY <= maxY) {
            // While within the boundary
            while (x >= minX && x <= maxX && y >= minY && y <= maxY) {
                order.emplace_back(matrix[y][x]);
                x += dx[dir];
                y += dy[dir];
            }

            // The current position is out of bound, undo the last step
            x -= dx[dir];
            y -= dy[dir];

            // Narrow the boundary accordingly
            if (dir == 0)
                ++minY;  // Going right
            else if (dir == 1)
                --maxX;  // Going down
            else if (dir == 2)
                --maxY;  // Going left
            else
                ++minX;  // Going up
            
            // Change the direction
            dir = (dir + 1) % 4;
            
            // Move into the new boundary
            x += dx[dir];
            y += dy[dir];
        }
        return order;
    }
};