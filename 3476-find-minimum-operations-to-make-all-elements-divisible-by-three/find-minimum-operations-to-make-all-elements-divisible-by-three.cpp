class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int rem = nums[i]%3;
            if(rem != 0) ans += min(rem, 3-rem);
        }
        return ans;
    }
};