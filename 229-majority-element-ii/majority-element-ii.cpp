class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int require = n / 3;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        
        int count = 1;
        int num = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == num) {
                count++;
            } else {
                if (count > require) {
                    ans.push_back(num);
                }
                num = nums[i];
                count = 1; 
            }
        }
        
        if (count > require) {
            ans.push_back(num);
        }
        
        return ans;
    }
};