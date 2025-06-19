class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = nums[0];
        int ans = 1; //minimum 1 is needed
        for(int i = 1; i < n; i++){
            if(nums[i] - start > k){
                ans++;
                start = nums[i];
            }
        }
        return ans;
    }
};