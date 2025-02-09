class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        for (int i = 0; i < n; ++i) {
            int transformedValue = nums[i] - i;
            freqMap[transformedValue]++;
        }
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long goodPairs = 0;
        for (auto& [key, value] : freqMap) {
            if (value >= 2) {
                goodPairs += (long long)value * (value - 1) / 2;
            }
        }
        long long badPairs = totalPairs - goodPairs;
        return badPairs;
    }
};