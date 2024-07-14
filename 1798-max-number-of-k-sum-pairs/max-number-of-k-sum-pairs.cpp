class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > k){
                index = i;
                break;
            }
        }

        int left = 0;
        int right = index;
        int op = 0;
        while(left < right){
            if((nums[left] + nums[right]) == k){
                op++;
                left++;
                right--;
            }
            else if((nums[left] + nums[right])> k){
                right--;
            }
            else{
                left++;
            }
        }

        return op;
    }
};