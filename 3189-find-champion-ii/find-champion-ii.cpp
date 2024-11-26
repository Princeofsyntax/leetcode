class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }
        vector<int> zeroInDegree;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push_back(i);
            }
        }
        if (zeroInDegree.size() == 1) {
            return zeroInDegree[0];
        }
        return -1;
    }
};