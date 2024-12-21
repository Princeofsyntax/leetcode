class Solution {
public:
    int maxComponents = 0;

    long long dfs(int node, vector<vector<int>>& graph, vector<int>& values, vector<bool>& visited, int k){
        visited[node] = true;
        long long subtreeSum = values[node];
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                long long childSum = dfs(neighbor, graph, values, visited, k);
                if (childSum % k == 0) {
                    maxComponents++;
                } else {
                    subtreeSum += childSum;
                }
            }
        }
        return subtreeSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // vector<bool> visited(n, false);
        // int totalSum = dfs(0, graph, values, visited, k);
        // if (totalSum % k == 0) {
        //     maxComponents++;
        // }
        // return maxComponents;
        // Optimize adjacency list by ensuring sorted traversal for cache friendliness
        for (auto& neighbors : graph) {
            sort(neighbors.begin(), neighbors.end());
        }
        vector<bool> visited(n, false);
        long long totalSum = dfs(0, graph, values, visited, k);
        if (totalSum % k == 0) {
            maxComponents++;
        }
        return maxComponents;
    }
};