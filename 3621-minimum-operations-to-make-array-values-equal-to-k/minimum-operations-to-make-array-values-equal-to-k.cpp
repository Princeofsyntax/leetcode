class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //if(find(nums.begin(), nums.end(), k) == nums.end()) return -1;
        for(int num : nums){
            if(num < k)return -1;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int ops = 0;
        int currentMax = nums[0];
        //operations
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > k && nums[i] != currentMax){
                currentMax = nums[i];
                ops++;
            }
        }
        if(currentMax > k)ops++;
        return ops;
    }
};