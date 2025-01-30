class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time}); 
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; //{distance, node}
        pq.push({0, 0});

        vector<long long> distance(n, LLONG_MAX); //distance[i] = minimum time to reach node i
        distance[0] = 0;

        vector<int> ways(n, 0); //number of ways to reach node i with the shortest time
        ways[0] = 1;

        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist > distance[u]) {
                continue;
            }
            for (const auto& [v, time] : graph[u]) {
                if (distance[u] + time < distance[v]) {
                    distance[v] = distance[u] + time;
                    ways[v] = ways[u]; // Reset the number of ways
                    pq.push({distance[v], v});
                } else if (distance[u] + time == distance[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // Add the number of ways
                }
            }
        }
        return ways[n - 1];
    }
};