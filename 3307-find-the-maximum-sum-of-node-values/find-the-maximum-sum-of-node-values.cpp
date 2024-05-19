class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int>netChange(n);
        long long nodeSum = 0;

        for (int i = 0; i < n; i++) {
            netChange[i] = (nums[i] ^ k) - nums[i];
            nodeSum += nums[i];
        }

        sort(netChange.begin(), netChange.end());

        for (int i = n-1; i >= 1; i -= 2) {
            // If netChange contains odd number of elements break the loop
            if (i - 1 == -1) {
                break;
            }
            long long pairSum = netChange[i] + netChange[i - 1];
            // Include in nodeSum if pairSum is positive
            if (pairSum > 0) {
                nodeSum += pairSum;
            } else {
                return nodeSum;
            }
        }
        return nodeSum;

    }
};