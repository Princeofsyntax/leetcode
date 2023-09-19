class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         for (int i = 0; i < nums.size()-1; i++)
    {
        //for every element , will traverse on aage waale elements
        for (int j = i+1; j < nums.size() ; j++)
        {
            
            if (nums[i] + nums[j] == target)
            {
               return {i,j};
            }
            
        } 
    }
    //not found
    return{};
    }
};