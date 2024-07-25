class Solution {
public:
    int dfs(int node, unordered_map<int, vector<int>>& adj, unordered_map<int, vector<int>>& reverseAdj, vector<bool>& visited) {
        visited[node] = true;
        int changeCount = 0;

        // Explore all outgoing edges
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                changeCount += 1 + dfs(neighbor, adj, reverseAdj, visited);
            }
        }

        // Explore all incoming edges
        for (int neighbor : reverseAdj[node]) {
            if (!visited[neighbor]) {
                changeCount += dfs(neighbor, adj, reverseAdj, visited);
            }
        }

        return changeCount;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;
        unordered_map<int, vector<int>> reverseAdj;

        for (const auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            reverseAdj[connection[1]].push_back(connection[0]);
        }

        // Visited array to keep track of visited cities
        vector<bool> visited(n, false);
        return dfs(0, adj, reverseAdj, visited);
    }
};