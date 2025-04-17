class Solution {
public:
    bool check(int i, int j, vector<int>& nums, int k){
        return ((i * j) % k == 0);
    }

    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] == nums[j] && check(i,j,nums,k))
                    ans++;
            }
        }
        return ans;
    }
};
