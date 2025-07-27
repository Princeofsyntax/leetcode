class Solution {
public:
    bool isHill(int index, vector<int>&nums){
        int n = nums.size();
        int left = index-1;
        int right = index+1;
        while(left >= 0 && nums[index] == nums[left]) left--;
        while(right < n && nums[index] == nums[right]) right++;
        if(left >= 0 && right < n) {
            if((nums[left] < nums[index]) && (nums[right] < nums[index])) return true;
        }
        return false;
    }

    bool isValley(int index, vector<int>&nums){
        int n = nums.size();
        int left = index-1;
        int right = index+1;
        while(left >= 0 && nums[index] == nums[left]) left--;
        while(right < n && nums[index] == nums[right]) right++;
        if(left >= 0 && right < n) {
            if((nums[left] > nums[index]) && (nums[right] > nums[index])) return true;
        }
        return false;
    }

    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0; 
        for (int i = 1; i < n - 1; i++) {
            if (isHill(i, nums) || isValley(i, nums)) count++;
            while (i + 1 < n && nums[i] == nums[i+1]) i++;
        }
        return count;
    }
};