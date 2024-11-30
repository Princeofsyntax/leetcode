class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }
        int startNode = pairs[0][0];  
        for (const auto& [node, outDeg] : outDegree) {
            if (outDeg - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }
        stack<int> stk;
        vector<int> path;
        stk.push(startNode);

        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                int nextNode = graph[node].back();
                graph[node].pop_back();
                stk.push(nextNode);
            } else {
                path.push_back(node);
                stk.pop();
            }
        }

        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }
        return result;
    }
};