class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Do XOR operation on whole array --> the unique one will only be left
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};