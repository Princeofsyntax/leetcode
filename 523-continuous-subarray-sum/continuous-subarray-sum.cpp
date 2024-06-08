class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndexMap;
        modIndexMap[0] = -1; // Initialize with a special case to handle edge case // when subarray is from start
        int sum = 0;
      
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i]; 
            int mod = sum % k; 
          
            // Check if the modulus has been seen before
            if (modIndexMap.count(mod)) {
                // If the distance between two same modulus is at least 2,
                // it indicates a subarray sum that is a multiple of k
                if (i - modIndexMap[mod] >= 2) return true;
            } else {
                // If this modulus hasn't been seen before, record its index
                modIndexMap[mod] = i;
            }
        }
      
        // If no qualifying subarray is found, return false
        return false;
    }
};