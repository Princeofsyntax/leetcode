class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // First, we sort the numbers.
        sort(nums.begin(), nums.end());
      
        // This will hold the unique triplets.
        vector<vector<int>> result;
      
        // Calculate the number of elements.
        int numElements = nums.size();
      
        // Start the first pointer `i` from the beginning of the array
        // and iterate over the numbers as long as there are at least 
        // two more elements after it and the current element is not positive.
        for (int i = 0; i < numElements - 2 && nums[i] <= 0; ++i) {
            // If this is not the first element and it's the same as the one before,
            // we skip it to avoid duplicate solutions.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
          
            // Pointers `j` and `k` initialize to elements after `i` and the last element respectively.
            int j = i + 1, k = numElements - 1;
          
            // While `j` is before `k` we look for valid triplets.
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
              
                // If current sum is less than zero, increment `j` to get closer to zero.
                if (sum < 0) {
                    ++j;
                } 
                // If current sum is greater than zero, decrement `k` to get closer to zero.
                else if (sum > 0) {
                    --k;
                }
                // If the sum is zero, we found a triplet.
                else {
                    // Add the current triplet to the result.
                    result.push_back({nums[i], nums[j], nums[k]});
                  
                    // Increment `j` and decrement `k` to find the next unique triplet.
                    ++j;
                    --k;
                  
                    // Skip duplicate values from `j` and `k` for the unique triplet.
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
      
        // Return the set of triplets found.
        return result;
    }
};