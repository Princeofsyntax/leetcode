class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);  //to track in-degrees for the reversed graph
        vector<vector<int>> reverseGraph(n);  
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                ++inDegree[i];
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;  
            for (int neighbor : reverseGraph[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};