class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int d = 0; // direction index
        int steps = 1; // number of steps to move in current direction
        int r = rStart, c = cStart; // current position
        
        result.push_back({r, c}); // starting position
        
        while (result.size() < rows * cols) {
            for (int i = 0; i < 2; ++i) { // repeat twice for each step size
                for (int j = 0; j < steps; ++j) {
                    r += directions[d][0];
                    c += directions[d][1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                d = (d + 1) % 4; // change direction
            }
            ++steps; // increase the step size after every two directions
        }
        
        return result;
    }
};