struct IndexedQuery {
    int queryIndex;
    int a; // Alice's index
    int b; // Bob's index
};

class Solution {
public:
    vector<IndexedQuery> getIndexedQueries(const vector<vector<int>>& queries) {
        vector<IndexedQuery> indexedQueries;
        // Convert queries into IndexedQuery format
        for (int i = 0; i < queries.size(); ++i) {
            int a = min(queries[i][0], queries[i][1]);
            int b = max(queries[i][0], queries[i][1]);
            indexedQueries.push_back({i, a, b});
        }
        // Sort the queries in descending order of b
        sort(indexedQueries.begin(), indexedQueries.end(), [](const IndexedQuery& a, const IndexedQuery& b) {
                return a.b > b.b;
        });
        return indexedQueries;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);
        vector<int> stack; // Monotonic stack to store indices in descending order of heights
        int heightsIndex = heights.size() - 1;
        for (const auto& [queryIndex, a, b] : getIndexedQueries(queries)) {
            if (a == b || heights[a] < heights[b]) {
                // If Alice and Bob are at the same index or Alice can jump directly
                ans[queryIndex] = b;
            } else {
                // Add heights with index > b to the stack in a monotonic manner
                while (heightsIndex > b) {
                    while (!stack.empty() && heights[stack.back()] <= heights[heightsIndex])
                        stack.pop_back();
                    stack.push_back(heightsIndex--);
                }
                // Find the smallest index j > b such that heights[j] > heights[a]
                auto it = upper_bound(stack.rbegin(), stack.rend(), a, [&](int a, int b) {
                    return heights[a] < heights[b];
                });

                if (it != stack.rend())
                    ans[queryIndex] = *it;
            }
        }
        return ans;
    }
};