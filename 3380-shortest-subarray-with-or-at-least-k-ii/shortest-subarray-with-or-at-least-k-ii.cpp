class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n+1;
        int orVal = 0;
        vector<int>bitCalculation(32,0);
        for(int i = 0, j = 0; j < n; j++){
            orVal |= nums[j];
            for(int h = 0; h < 32; h++){
                if(nums[j] & (1 << h))bitCalculation[h]++;
            }
            while(orVal >= k && i <= j){
                ans = min(ans, j-i+1);
                // shrink the sliding window
                for(int h = 0; h < 32; h++){
                    if(nums[i] & (1 << h)){
                        if(--bitCalculation[h] == 0){
                            orVal ^= (1 << h);
                        }
                    }
                }
                i++;
            }

        }
        return ans > n ? -1 : ans;
    }
};