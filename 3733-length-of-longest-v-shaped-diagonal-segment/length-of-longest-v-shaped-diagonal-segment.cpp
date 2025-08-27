class Solution {
public:
    // This function calculates the length of the longest V-shaped diagonal path.
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        // Get the dimensions of the grid.
        int m = grid.size();
        int n = grid[0].size();

        // Define the 4 possible diagonal directions:
        // 0: Down-Right, 1: Down-Left, 2: Up-Left, 3: Up-Right.
        // The order allows for a 90-degree clockwise turn by doing (direction + 1) % 4.
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

        // Memoization table to store results of subproblems.
        // Dimensions: [row][col][direction][can_turn]
        // It stores the length of the longest path starting from (row, col)
        // in a given 'direction' and whether a 'turn' is still allowed.
        int memo[m][n][4][2];
        // Initialize the memoization table with -1 to indicate that no states have been computed yet.
        memset(memo, -1, sizeof(memo));

        // Define the recursive DFS function using a lambda.
        // It explores paths and returns the length of the path from the *next* cell onwards.
        // Parameters:
        // cx, cy: current coordinates
        // direction: current direction of travel
        // turn: a boolean, true if a 90-degree turn is still allowed
        // target: the value expected in the next cell (e.g., if current is 1, target is 2)
        function<int(int, int, int, bool, int)> dfs =
            [&](int cx, int cy, int direction, bool turn, int target) -> int {
            
            // Calculate coordinates of the next cell in the current direction.
            int nx = cx + dirs[direction][0];
            int ny = cy + dirs[direction][1];

            // Base Case: Stop recursion if the next cell is out of bounds
            // or if its value does not match the target value.
            // This path ends here, so its future length is 0.
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
                return 0;
            }
            
            // If this state has already been computed, return the stored result.
            if (memo[nx][ny][direction][turn] != -1) {
                return memo[nx][ny][direction][turn];
            }

            // --- Recursive Step ---

            // Option 1: Continue moving straight in the same direction.
            // The 'turn' status remains the same, and the next target value flips (2 -> 1 or 1 -> 2).
            int maxStep = dfs(nx, ny, direction, turn, 2 - target);

            // Option 2: Make a 90-degree turn (if allowed).
            if (turn) {
                // Explore the path after making a 90-degree clockwise turn.
                // The 'turn' flag is set to 'false' because only one turn is permitted.
                int newDirection = (direction + 1) % 4;
                int turnedPath = dfs(nx, ny, newDirection, false, 2 - target);
                // The longest path from (nx, ny) is the max of going straight vs. turning.
                maxStep = fmax(maxStep, turnedPath);
            }
            
            // Store the result in the memoization table.
            // The length is maxStep (length from the *next* cell) + 1 (for the current step).
            memo[nx][ny][direction][turn] = maxStep + 1;
            return maxStep + 1;
        };

        // This variable will store the final maximum length found.
        int res = 0;
        
        // Iterate through every cell in the grid to find all possible starting points.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // A valid V-shaped path must start at a cell with value 1.
                if (grid[i][j] == 1) {
                    // From this starting cell, try initiating a path in all 4 diagonal directions.
                    for (int direction = 0; direction < 4; ++direction) {
                        // Call DFS for a path starting at (i, j).
                        // - direction: The initial direction.
                        // - turn: true, because a turn is allowed from the start.
                        // - target: 2, since we are starting at a cell with value 1.
                        // The '+ 1' accounts for the starting cell itself.
                        int currentPathLength = dfs(i, j, direction, true, 2) + 1;
                        res = fmax(res, currentPathLength);
                    }
                }
            }
        }

        // Return the overall maximum length found.
        return res;
    }
};