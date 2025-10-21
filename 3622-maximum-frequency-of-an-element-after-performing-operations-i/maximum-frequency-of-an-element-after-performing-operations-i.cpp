class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int maxOperations) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int range = maxVal + k + 2;
        // sort(nums.begin(),nums.end());
        vector<int>helper(range,0);
        for(const auto& num : nums){
            helper[num]++;
        }
        // long long Toperations = 0;
        // int l = 0, maxF = 1;
        // for(int r = 0; r < n; r++){
        //     // if(r > 0) Toperations += (long long)(nums[r] - nums[r-1])*(r-l);
        //     Toperations += (long long)nums[r];
        //     long long targetSum = (long long)nums[r] * (r-l+1);
        //     while(targetSum - Toperations > (long long)numOperations){
        //         Toperations -= nums[l];
        //         l++;
        //     }
        //     maxF = max(maxF,r-l+1);
        // }
        // return maxF;

        vector<int>preSum(range,0);
        preSum[0] = helper[0];
        for(int i = 1; i < range; i++){
            preSum[i] = preSum[i-1]+helper[i];
        }
        int maxF = 0;
        for(int i = 0; i < range; i++){
            if(helper[i] == 0 && maxOperations == 0)continue;
            int lBound = max(0, i - k);
            int rBound = min(range - 1, i + k);
            int totalRange = preSum[rBound] - (lBound > 0 ? preSum[lBound - 1] : 0);
            int adjust = totalRange - helper[i];
            int currentTotal = helper[i] + min(maxOperations, adjust);

            maxF = max(maxF, currentTotal);
        }
        return maxF;
    }
};