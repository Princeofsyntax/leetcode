class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Function to perform topological sorting and return the order of elements
        auto topologicalSort = [&](vector<vector<int>>& conditions) {
            vector<int> inDegree(k + 1, 0);
            unordered_map<int, vector<int>> graph;

            // Build the graph and in-degree array
            for (auto& cond : conditions) {
                int u = cond[0], v = cond[1];
                graph[u].push_back(v);
                inDegree[v]++;
            }

            // Queue for nodes with no incoming edges
            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                for (int neighbor : graph[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            // If order contains all k elements, return the order, otherwise return an empty vector
            return order.size() == k ? order : vector<int>{};
        };

        // Get the row order and column order using topological sorting
        vector<int> rowOrder = topologicalSort(rowConditions);
        vector<int> colOrder = topologicalSort(colConditions);

        // If either order is empty, return an empty matrix
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        // Create a position map for rowOrder and colOrder
        unordered_map<int, int> rowPos, colPos;
        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        // Build the matrix based on rowPos and colPos
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            matrix[rowPos[i]][colPos[i]] = i;
        }

        return matrix;
    }
};