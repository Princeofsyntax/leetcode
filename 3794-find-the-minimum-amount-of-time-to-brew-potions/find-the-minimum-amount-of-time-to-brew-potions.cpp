#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        if (m == 0) {
            return 0;
        }

        vector<long long> prev_finish_times(n);

        long long potion_0_pipeline_time = 0;
        for (int i = 0; i < n; ++i) {
            potion_0_pipeline_time += (long long)skill[i] * mana[0];
            prev_finish_times[i] = potion_0_pipeline_time;
        }

        for (int j = 1; j < m; ++j) {
            long long start_time_j = 0;
            long long current_prefix_sum_T = 0;

            for (int i = 0; i < n; ++i) {
                long long required_start = prev_finish_times[i] - current_prefix_sum_T;
                if (required_start > start_time_j) {
                    start_time_j = required_start;
                }
                current_prefix_sum_T += (long long)skill[i] * mana[j];
            }

            long long current_potion_pipeline_time = 0;
            for (int i = 0; i < n; ++i) {
                current_potion_pipeline_time += (long long)skill[i] * mana[j];
                prev_finish_times[i] = start_time_j + current_potion_pipeline_time;
            }
        }

        return prev_finish_times[n - 1];
    }
};