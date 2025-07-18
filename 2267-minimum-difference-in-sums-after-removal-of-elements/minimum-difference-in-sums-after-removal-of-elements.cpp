class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;
        vector<long long> prefix_mins(N, -1);
        priority_queue<int> max_pq; 
        long long current_sum = 0;

        for (int i = 0; i < N; ++i) {
            current_sum += nums[i];
            max_pq.push(nums[i]);

            if (max_pq.size() > n) {
                current_sum -= max_pq.top();
                max_pq.pop();
            }

            if (max_pq.size() == n) {
                prefix_mins[i] = current_sum;
            }
        }

        vector<long long> suffix_maxs(N, -1);
    
        priority_queue<int, vector<int>, greater<int>> min_pq; 
        current_sum = 0;

        for (int i = N - 1; i >= 0; --i) {
            current_sum += nums[i];
            min_pq.push(nums[i]);

            if (min_pq.size() > n) {
                current_sum -= min_pq.top();
                min_pq.pop();
            }

            if (min_pq.size() == n) {
                suffix_maxs[i] = current_sum;
            }
        }

        long long min_diff = LLONG_MAX;

        for (int i = n - 1; i < 2 * n; ++i) {
            long long sum_first = prefix_mins[i];
            long long sum_second = suffix_maxs[i + 1];
            min_diff = std::min(min_diff, sum_first - sum_second);
        }

        return min_diff;
    }
};