class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int consecutiveLength[n];
        consecutiveLength[0] = 1;
        for (int i = 1; i < n; ++i) {
            consecutiveLength[i] = (nums[i] == nums[i - 1] + 1) ? consecutiveLength[i - 1] + 1 : 1;
        }

        vector<int> result;
        for (int i = k - 1; i < n; ++i) {
            result.push_back(consecutiveLength[i] >= k ? nums[i] : -1);
        }
        return result;
    }
};
