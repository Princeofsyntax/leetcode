class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
      return a.first < b.first; 
    } 

    vector<int> twoSum(vector<int>& nums, int target) {
      //First store the indices corresponding to its value so that we can do sorting without loss of indices
      //Sort the array and then use 2 pointer approach
      vector<pair<int,int>>data;
      for(int i = 0; i < nums.size(); i++)
      {
        int value = nums[i];
        int index = i;
        data.push_back({value,index});
      }

      sort(data.begin(), data.end(), cmp); //sorting w.r.t value

      int start = 0;
      int end = data.size()-1;
      vector<int>ans;

      while(start < end)
       {
         if(data[start].first + data[end].first == target)
         {
            ans.push_back(data[start].second); 
            ans.push_back(data[end].second); 
            break;
         }
         else if(data[start].first + data[end].first > target)
         {
            end--;
         }
         else
         {
            start++;
         }
      }
      return ans;
    }
};