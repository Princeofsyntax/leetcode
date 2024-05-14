class Solution {
public:
    // Directions array representing the 4 possible movements: up, right, down, left.
    vector<int> directions = {-1, 0, 1, 0, -1};

    // Main function to call for getting the maximum gold.
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
      
        // Iterate over each cell in the grid.
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // Compute the maximum gold recursively starting from the current cell.
                maxGold = max(maxGold, dfs(i, j, grid));
            }
        }
      
        return maxGold;
    }

private:
    // Helper DFS function to explore the grid for gold collection.
    int dfs(int x, int y, vector<vector<int>>& grid) {
        // Boundary check and cell with zero gold check
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
      
        int gold = grid[x][y];  // Store the gold in the current cell.
        grid[x][y] = 0;         // Mark the current cell as visited by setting it to 0.
      
        int maxGoldFromHere = 0;
      
        // Explore all 4 adjacent cells.
        for (int i = 0; i < 4; ++i) {
            // Recursively collect the gold by going in one direction.
            int nextGold = dfs(x + directions[i], y + directions[i + 1], grid);
            // Update the maximum gold collected from the current path.
            maxGoldFromHere = max(maxGoldFromHere, gold + nextGold);
        }
      
        grid[x][y] = gold;  // Reset the cell to its original gold value.
      
        return maxGoldFromHere;  // Return the maximum gold obtained starting from (x, y).
    }
};