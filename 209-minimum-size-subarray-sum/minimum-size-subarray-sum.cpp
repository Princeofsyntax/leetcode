class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //Firstly create start and end pointers at begining 
        //If sum is less than target than move end forward; when sum becomes greater or equal to target , store answer and reduce window by moving start forward
        //Repeat the step
        int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MAX;

        while(j < nums.size()){
            //include current number
            sum = sum + nums[j];
            //we are ready with a window sum
            while(sum >= target){
                //minimise --> decrease from sum / store length
                len = min(len, j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        if(len == INT_MAX){
            return 0;
        }
        else{
            return len;
        }
    }
};