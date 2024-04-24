class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0; // Handle edge case of empty grid

        map<pair<int,int>, bool> visited;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    visited[{i,j}] = true; 
                }
            }
        }

        int ans = 0;

        // Iterate over all land cells
        for(auto v : visited){
            auto pair = v.first;
            int x = pair.first;
            int y = pair.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i = 0; i< 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                // Check if the adjacent cell is within bounds and water
                if(newX < 0 || newY < 0 || newX >= rows || newY >= cols || grid[newX][newY] == 0){
                    ans++; // Increment perimeter if adjacent cell is out of bounds or water
                }
            }
        }
        return ans;
    }
};