class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int extra = totalSum % p;
        if (extra == 0) return 0;  

        unordered_map<int, int> mod_map;  
        mod_map[0] = -1;  
        long long currentSum = 0;
        int minLength = nums.size();  

        for (int i = 0; i < nums.size(); i++) {
            currentSum = (currentSum + nums[i]) % p;

            int target = (currentSum - extra + p) % p;

            if (mod_map.find(target) != mod_map.end()) {
                minLength = min(minLength, i - mod_map[target]);
            }

            mod_map[currentSum] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};