class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subtree_xor;
    vector<int> start_time;
    vector<int> end_time;
    int timer;

    void dfs(int u, int p, vector<int>&nums){
        start_time[u] = timer++;
        subtree_xor[u] = nums[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, nums);
            subtree_xor[u] ^= subtree_xor[v];
        }
        end_time[u] = timer++;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        subtree_xor.assign(n, 0);
        start_time.assign(n, 0);
        end_time.assign(n, 0);
        timer = 0;

        dfs(0, -1, nums);
        
        int total_xor = subtree_xor[0];
        int min_score = INT_MAX;

        //iterate through all possible pairs of edges to remove
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int xor1, xor2, xor3;

                //check for ancestor-descendant relationship using pre-computed times
                bool i_is_ancestor_of_j = (start_time[i] < start_time[j] && end_time[i] > end_time[j]);
                bool j_is_ancestor_of_i = (start_time[j] < start_time[i] && end_time[j] > end_time[i]);

                if (i_is_ancestor_of_j) {
                    // Case 1: Nested cut
                    xor1 = subtree_xor[j];
                    xor2 = subtree_xor[i] ^ subtree_xor[j];
                    xor3 = total_xor ^ subtree_xor[i];
                } else if (j_is_ancestor_of_i) {
                    // Case 2: Nested cut (symmetric)
                    xor1 = subtree_xor[i];
                    xor2 = subtree_xor[j] ^ subtree_xor[i];
                    xor3 = total_xor ^ subtree_xor[j];
                } else {
                    // Case 3: Independent cuts
                    xor1 = subtree_xor[i];
                    xor2 = subtree_xor[j];
                    xor3 = total_xor ^ subtree_xor[i] ^ subtree_xor[j];
                }

                int score = max({xor1, xor2, xor3}) - min({xor1, xor2, xor3});
                min_score = min(min_score, score);
            }
        }
        
        return min_score;
    }
};