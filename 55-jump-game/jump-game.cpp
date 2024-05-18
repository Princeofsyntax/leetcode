class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        //we have to check from each index that how much maximum we can reach

        for(int i = 0; i < n; i++){
           if(maxReach < i) return false; //as if we cant reach index i then how we can reach to last!!

           maxReach = max(maxReach , i + nums[i]);
        }

        return maxReach >= n-1;
    }
};