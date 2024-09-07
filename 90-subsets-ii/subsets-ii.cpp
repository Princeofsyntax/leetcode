class Solution {
public:
    void helper(vector<vector<int>>&ans, int index, vector<int>&curr, vector<int>& nums){
        ans.push_back(curr);

        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            helper(ans, i+1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        helper(ans, 0, curr, nums);
        return ans;
    }
};