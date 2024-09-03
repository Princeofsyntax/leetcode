class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int require = n/2;

        sort(nums.begin(), nums.end());
        
        int i = 1;
        int count = 1;
        int num = nums[0];
        while(i < n){
           if (nums[i] == num) {
                count++;
                i++;
            } else {
                if (count > require) {
                    return num;
                }
                num = nums[i];
                count = 1; 
                i++;
            }
        }

        if (count > require) {
            return num;
        }
        
        return 0;
    }
};