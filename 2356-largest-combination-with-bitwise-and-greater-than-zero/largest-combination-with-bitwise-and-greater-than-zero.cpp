class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCombinationSize = 0;

        // We will count bits up to the 24th position (since max candidate is <= 10^7)
        for (int bit = 0; bit < 24; ++bit) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << bit)) { 
                    // Check if the bit is set
                    ++count;
                }
            }
            maxCombinationSize = max(maxCombinationSize, count);
        }

        return maxCombinationSize;
    }
};