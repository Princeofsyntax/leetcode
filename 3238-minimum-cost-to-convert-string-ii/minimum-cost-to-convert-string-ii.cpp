class Solution {
public:
    static const unsigned long long INF = ULLONG_MAX;

    long long minimumCost(string source,string target,vector<string>& original,vector<string>& changed,vector<int>& cost) {
        int n = source.size();
        int m = original.size();

        // Map each string to an ID
        unordered_map<string, int> id;
        unordered_set<int> lengths;

        int idx = 0;

        // Distance matrix between strings
        unsigned long long dist[201][201];
        memset(dist, 255, sizeof(dist));   // INF

        // Assign IDs and fill direct conversion costs
        for (int i = 0; i < m; i++) {
            if (!id.count(original[i])) {
                id[original[i]] = idx++;
                lengths.insert(original[i].size());
            }
            if (!id.count(changed[i])) {
                id[changed[i]] = idx++;
            }

            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (unsigned long long)cost[i]);
        }

        // Cost to convert a string to itself is 0
        for (int i = 0; i < idx; i++) {
            dist[i][i] = 0;
        }

        // Floyd–Warshall to get minimum cost between all string pairs
        for (int k = 0; k < idx; k++) {
            for (int i = 0; i < idx; i++) {
                for (int j = 0; j < idx; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // DP[i] = minimum cost to convert source[0..i-1]
        unsigned long long dp[1001];
        memset(dp, 255, sizeof(dp));  // INF
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // Case 1: characters already match
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Case 2: try replacing substrings
            for (int L : lengths) {
                if (i + L > n) continue;

                string s = source.substr(i, L);
                string t = target.substr(i, L);

                if (id.count(s) && id.count(t)) {
                    unsigned long long c = dist[id[s]][id[t]];
                    if (c != INF) {
                        dp[i + L] = min(dp[i + L], dp[i] + c);
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
