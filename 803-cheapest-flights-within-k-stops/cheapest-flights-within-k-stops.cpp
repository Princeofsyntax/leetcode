class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        // Min-heap {cost, current city, stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);
        // Track minimum cost and stops per city
        vector<int> minCost(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        minCost[src] = 0;
        stops[src] = 0;

        while (!pq.empty()) {
            auto [cost, city, stopCount] = pq.top();
            pq.pop();
            if (city == dst) return cost;  //if here stops > k that means destination node is also included so no worry
            if (stopCount > k) continue;  

            for (const auto& [neighbor, price] : graph[city]) {
                int newCost = cost + price;
                int newStops = stopCount + 1;
                // Only push to queue if:
                // 1. The new path is cheaper than the previously recorded cost
                // 2. OR we reached it with fewer stops (potential for cheaper paths)
                if (newCost < minCost[neighbor] || newStops < stops[neighbor]) {
                    minCost[neighbor] = newCost;
                    stops[neighbor] = newStops;
                    pq.emplace(newCost, neighbor, newStops);
                }
            }
        }
        return -1;
    }
};