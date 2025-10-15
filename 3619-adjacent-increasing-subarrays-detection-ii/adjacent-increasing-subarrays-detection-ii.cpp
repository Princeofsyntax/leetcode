class Solution {
public:
    // bool helper(vector<int>&nums, int start, int k){
    //     for(int i = start; i < start+k-1; i++){
    //         if(nums[i] >= nums[i+1])return false;
    //     }
    //     return true;
    // }

    // bool isAcceptable(vector<int>&nums, int k){
    //     for(int i = 0; i <= nums.size() - 2*k; i++){
    //         if(helper(nums,i,k) && helper(nums, i+k, k))return true;
    //     }
    //     return false;
    // }

    bool isValidd(vector<int>&nums, vector<int>&increasingLength, int k){
        for(int i = 0; i <= nums.size() - 2*k; i++){
            if(increasingLength[i] >= k && increasingLength[i+k] >= k)return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int>increasingLength(n,1);
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]) increasingLength[i] = increasingLength[i+1]+1;
        }
        
        int l = 1;
        int r = n/2;
        int maxK = 0;
        while(l <= r){
            int m = l + (r-l)/2;
            if(isValidd(nums,increasingLength, m)){
                maxK = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return maxK;
    }
};