class Solution {
public:
    int maxTotalReward(std::vector<int>& rewardValues) {
        // Sort and remove duplicates to process rewards in increasing order
        // and avoid redundant computations.
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        // The max reward value is 50000. The max possible sum is less than
        // 50000 + 49999 = 99999. A bitset size of 100001 is sufficient.
        const int MAX_SUM = 100001;
        bitset<MAX_SUM> dp;
        
        // Initially, a total reward of 0 is achievable.
        dp[0] = 1;

        // For each reward 'r', update the set of achievable sums.
        for (int r : rewardValues) {
            // We can add 'r' to any sum 'x' if 'x < r'.
            // This is equivalent to taking the part of 'dp' for sums < r,
            // shifting it left by 'r', and merging it back.

            // 1. Isolate the bits of dp representing sums less than r.
            // We make a temporary copy to work with.
            bitset<MAX_SUM> temp_dp = dp;
            
            // A right shift by r followed by a left shift by r clears the lower r bits,
            // leaving only the bits for sums >= r.
            auto higher_bits = (temp_dp >> r) << r;

            // XORing the original with the higher_bits part isolates the lower_bits part (sums < r).
            auto lower_bits = temp_dp ^ higher_bits;
            
            // 2. Shift these lower_bits by r to represent adding the reward 'r'
            //    to all achievable sums that were smaller than 'r'.
            auto shifted_lower_bits = lower_bits << r;

            // 3. Update the main dp bitset with the new achievable sums.
            dp |= shifted_lower_bits;
        }

        // Find the maximum achievable reward by finding the highest set bit.
        for (int i = MAX_SUM - 1; i >= 0; --i) {
            if (dp[i]) {
                return i;
            }
        }
        
        // This case should not be reached as dp[0] is always 1.
        return 0;
    }
};