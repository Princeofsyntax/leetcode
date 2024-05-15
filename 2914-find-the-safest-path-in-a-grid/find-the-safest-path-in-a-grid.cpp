class UnionFind {
public:
    vector<int> parent;
    int count;

    // Constructor initializes UnionFind with `n` elements
    UnionFind(int n)
        : count(n), parent(n) {
        // Fill the parent vector with indices of itself (self parentage)
        iota(parent.begin(), parent.end(), 0);
    }

    // Unite two groups; if they are already united, return false
    bool unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB) return false;
        // Assign the parent of A's root to be B's root
        parent[rootA] = rootB;
        --count; // Decrease the number of disjoint sets
        return true;
    }

    // Find the root of the group that element `x` is in
    int find(int x) {
        // Path compression: point this node directly to the root
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
};

class Solution {
public:
    // Calculates the maximum safeness factor of a given grid
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int gridSize = grid.size();
        // If the start or end points are blocked, return 0
        if (grid[0][0] || grid[gridSize - 1][gridSize - 1]) {
            return 0;
        }

        queue<pair<int, int>> q; // Queue for BFS
        // Initialize distance array with large values
        int dist[gridSize][gridSize];
        memset(dist, 0x3f, sizeof(dist));

        // Calculate distances from each hazard in the grid
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                if (grid[i][j]) {
                    dist[i][j] = 0; // Hazards have zero distance
                    q.emplace(i, j); // Add hazards to the queue
                }
            }
        }

        // Directions for neighbors (up, right, down, left)
        int dirs[5] = {-1, 0, 1, 0, -1};

        // Perform BFS to calculate the distance of each cell from the closest hazard
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize && 
                    dist[x][y] == 0x3f3f3f3f) {
                    dist[x][y] = dist[i][j] + 1; // Update distance
                    q.emplace(x, y); // Enqueue the current cell
                }
            }
        }

        // Sort the cells by distance in descending order
        vector<tuple<int, int, int>> distances;
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                distances.emplace_back(dist[i][j], i, j);
            }
        }
        sort(distances.begin(), distances.end(), greater<>());

        // UnionFind to keep track of connectivity
        UnionFind uf(gridSize * gridSize);

        // Try to unite cells, starting from the highest distance from hazards
        for (auto [distance, i, j] : distances) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize && dist[x][y] >= distance) {
                    uf.unite(i * gridSize + j, x * gridSize + y);
                }
            }
            // If the start and end points are connected, return the current distance
            if (uf.find(0) == uf.find(gridSize * gridSize - 1)) {
                return distance;
            }
        }

        // If no path is found, return 0
        return 0;
    }
};