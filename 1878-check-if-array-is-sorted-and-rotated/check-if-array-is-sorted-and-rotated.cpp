class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int index = -1;  
        for(int i = 0; i < n; i++){
            if(i < n - 1 && nums[i] > nums[i + 1]){
                index = i + 1;  
                break;
            }
        }
        if(index == -1) return true;

        for(int i = 1; i < index; i++){
            if(nums[i - 1] > nums[i]) return false;
        }
        
        for(int i = index + 1; i < n; i++){
            if(nums[i - 1] > nums[i]) return false;
        }
        if(nums[0] < nums[n - 1]) return false;
        
        return true;
    }
};
