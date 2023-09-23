class Solution {
public:
    
    int findPairs(vector<int>& nums, int k) {
          //sort
    sort(nums.begin(),nums.end());
    set<pair<int,int>> ans;  //set stores unique item and pair-->stores pairs of items
    int i=0,j=1;
    while (j< nums.size())
    {
        int diff=nums[j]-nums[i];
        if (diff==k)
        {
            ans.insert({nums[i],nums[j]});  //insertion in pair data structure
            i++,j++;
        }
        else if (diff>k)
        {
            i++;
        }
        else{
            j++;
        }
        if (i==j)
        {
            j++;
        }
        
    }
    return ans.size();
    }
};