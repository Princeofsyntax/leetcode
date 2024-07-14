class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        // Handle edge cases
        if (k == 1 && nums.size() == 1) return static_cast<double>(nums[0]);
        if (k == 1 && nums.size() > 1) return static_cast<double>(*max_element(nums.begin(), nums.end()));

        // Calculate the initial window sum
        double windowSum = 0;
        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
        }

        // Initialize the maximum average with the first window average
        double maxAvg = windowSum / k;

        // Use sliding window to calculate the maximum average
        for (int i = k; i < nums.size(); ++i) {
            windowSum += nums[i] - nums[i - k];
            double currentAvg = windowSum / k;
            maxAvg = max(maxAvg, currentAvg);
        }

        return maxAvg;
    }
};