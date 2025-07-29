class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        vector<int>lastBit(32,-1); //the last bit where it was set
        for(int i = n-1; i >= 0; i--){
            for(int bit = 0; bit < 32; bit++){
                if((nums[i] >> bit) & 1) lastBit[bit] = i;
            }
            int maxi = i;
            for (int b = 0; b < 32; ++b) {
                if (lastBit[b] != -1) maxi = max(maxi, lastBit[b]);
            }
            ans[i] = maxi - i + 1;
        }
        return ans;
    }
};