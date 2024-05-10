class Solution {
public:
    // Custom comparator to compare fractions
    vector<int> kthSmallestPrimeFraction(std::vector<int>& primes, int k) {
        // Custom comparator function to compare fractions
        auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return primes[a.first] * primes[b.second] > primes[a.second] * primes[b.first];
        };

        // Priority queue to store fractions with custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        // Initialize priority queue with fractions {0, i} for i ranging from 1 to size - 1
        for (int i = 1; i < primes.size(); ++i) {
            pq.push({0, i});
        }

        // Pop k-1 elements to find k-th smallest fraction
        for (int i = 1; i < k; ++i) {
            auto fraction = pq.top();
            pq.pop();
            if (fraction.first + 1 < fraction.second) {
                pq.push({fraction.first + 1, fraction.second});
            }
        }

        // Retrieve k-th smallest fraction from top of priority queue
        return {primes[pq.top().first], primes[pq.top().second]};
    }
};
