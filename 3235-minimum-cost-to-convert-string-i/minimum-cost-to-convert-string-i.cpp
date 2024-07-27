class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>> minCost(26, vector<long long>(26, LLONG_MAX));

        // Initialize minCost for direct transformations
        for (int i = 0; i < original.size(); ++i) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            minCost[from][to] = min(minCost[from][to], static_cast<long long>(cost[i]));
        }

        // Set the cost of transforming a character to itself to 0
        for (int i = 0; i < 26; ++i) {
            minCost[i][i] = 0;
        }

        // Floyd-Warshall algorithm to compute all-pairs shortest paths
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (minCost[i][k] != LLONG_MAX && minCost[k][j] != LLONG_MAX) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        
        for (int i = 0; i < n; ++i) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (minCost[from][to] == LLONG_MAX) {
                return -1; // Impossible to transform
            }
            totalCost += minCost[from][to];
        }
        
        return totalCost;
    }
};