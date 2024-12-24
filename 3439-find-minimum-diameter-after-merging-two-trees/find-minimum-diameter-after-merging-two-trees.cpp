class Solution {
public:
    pair<int, int> bfs(int start, int n, const vector<vector<int>>& graph) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farthestNode = start, maxDist = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return {farthestNode, maxDist};
    }

    int calculateDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        int farthest = bfs(0, n, graph).first;
        // Second BFS to calculate the diameter of the tree
        int diameter = bfs(farthest, n, graph).second;
        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        int diameter1 = calculateDiameter(n1, edges1);
        int diameter2 = calculateDiameter(n2, edges2);
        // The new diameter is determined by the maximum of:
        // - The current diameters of both trees
        // - The sum of half the diameters of both trees plus 1
        int newDiameter = max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
        return newDiameter;
    }
};