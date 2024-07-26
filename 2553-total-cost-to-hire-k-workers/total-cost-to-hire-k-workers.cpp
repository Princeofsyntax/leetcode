class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total_cost = 0;

        // Create two priority queues: one for the first 'candidates' workers and one for the last 'candidates' workers.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq_first, pq_last;
        
        int n = costs.size();
        int left = 0, right = n - 1;

        // Fill the priority queues with the initial 'candidates' elements.
        for (int i = 0; i < candidates && left <= right; ++i) {
            pq_first.emplace(costs[left], left);
            if (left != right) {
                pq_last.emplace(costs[right], right);
            }
            ++left;
            --right;
        }

        // Perform 'k' hiring sessions.
        for (int i = 0; i < k; ++i) {
            if (!pq_first.empty() && (pq_last.empty() || pq_first.top() <= pq_last.top())) {
                auto [cost, index] = pq_first.top();
                pq_first.pop();
                total_cost += cost;

                // Add the next element from the left to the pq_first if available.
                if (left <= right) {
                    pq_first.emplace(costs[left], left);
                    ++left;
                }
            } else {
                auto [cost, index] = pq_last.top();
                pq_last.pop();
                total_cost += cost;

                // Add the next element from the right to the pq_last if available.
                if (left <= right) {
                    pq_last.emplace(costs[right], right);
                    --right;
                }
            }
        }

        return total_cost;
    }
};