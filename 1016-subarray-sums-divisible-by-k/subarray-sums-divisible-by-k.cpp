
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Create a hash map to store the frequency of each prefix sum mod k.
        unordered_map<int, int> prefixSumCount {{0, 1}};
        int countSubarrays = 0; // Initialize the number of subarrays divisible by k.
        int cumulativeSum = 0; // This will keep track of the cumulative sum of elements.

        // Iterate over each number in the array.
        for (int num : nums) {
            // Add current number to cumulative sum and do mod by k.
            // The double mod ensures that cumulativeSum is positive.
            cumulativeSum = ((cumulativeSum + num) % k + k) % k;

            // If a subarray has cumulativeSum mod k equals to some previous subarray's cumulativeSum mod k,
            // then the subarray in between is divisible by k.
            countSubarrays += prefixSumCount[cumulativeSum]++;

            // The prefixSumCount[cumulativeSum]++ increases the count of the
            // current prefix sum mod k, which will be used for future subarray checks.
        }

        // Return the total count of subarrays with sum divisible by k.
        return countSubarrays;
    }
};