class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>helper;

        int ans = -1;
        for(auto num : nums){
            if(helper.count(-num)){
                ans = max(ans, abs(num)); //to check if its negative is also present 
            }
            else{
                helper.insert(num);
            }
        }
        return ans;
    }
};