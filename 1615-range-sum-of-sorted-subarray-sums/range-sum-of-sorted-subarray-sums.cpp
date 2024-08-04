class Solution {
public:
    long long int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       vector<int> sum;
        // Generate all subarray sums
        for (int i = 0; i < nums.size(); i++) {
            int helper = nums[i];
            sum.push_back(helper % MOD);
            for (int j = i + 1; j < nums.size(); j++) {
                helper += nums[j];
                sum.push_back(helper % MOD);
            }
        }

        // Sort the subarray sums
        sort(sum.begin(), sum.end());

        // Calculate the sum from 'left' to 'right' (1-based indexing)
        long long ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sum[i]) % MOD;
        }

        return ans;

    }
};