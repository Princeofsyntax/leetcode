class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         // Create the graph
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];
            graph[A].emplace_back(B, value);
            graph[B].emplace_back(A, 1.0 / value);
        }

        // Function to perform DFS and find the result of the division
        function<double(const string&, const string&, unordered_set<string>&)> dfs = 
        [&](const string& start, const string& end, unordered_set<string>& visited) -> double {
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) return -1.0;
            if (start == end) return 1.0;

            visited.insert(start);
            for (auto& neighbor : graph[start]) {
                string nextNode = neighbor.first;
                double value = neighbor.second;
                if (visited.find(nextNode) == visited.end()) {
                    double res = dfs(nextNode, end, visited);
                    if (res != -1.0) {
                        return res * value;
                    }
                }
            }
            return -1.0;
        };

        // Process each query
        vector<double> results;
        for (auto& query : queries) {
            string C = query[0], D = query[1];
            unordered_set<string> visited;
            double result = dfs(C, D, visited);
            results.push_back(result);
        }

        return results;
    }
};