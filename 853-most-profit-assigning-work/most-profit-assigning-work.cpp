class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();

        // Use a vector to pair difficulties with profits
        vector<pair<int, int>> helper;
        for (int i = 0; i < n; ++i) {
            helper.push_back({difficulty[i], profit[i]});
        }

        // Sort by difficulty
        sort(helper.begin(), helper.end());

        // Sort workers by their ability
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int bestProfit = 0;
        int j = 0;

        // Iterate through each worker
        for (int i = 0; i < worker.size(); ++i) {
            // While the worker can handle the job, update the bestProfit
            while (j < n && worker[i] >= helper[j].first) {
                bestProfit = max(bestProfit, helper[j].second);
                ++j;
            }
            // Add the best profit this worker can achieve
            maxProfit += bestProfit;
        }

        return maxProfit;
    }
};