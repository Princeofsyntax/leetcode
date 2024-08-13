class Solution {
public:
    void combination_helper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    // base case
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
    {
        return;
    }

    // recusrion
    for (int i = index; i < candidates.size(); i++)
    {
        if( i > index && candidates[i] == candidates[i-1]){
            //we do not pick same element 
            continue;
        }

        v.push_back(candidates[i]);
        combination_helper(candidates, target - candidates[i], v, ans, i+1);//as we need different element (unique)
        // backtracking
        v.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end()); //so that [2,2,1] and [1,2,2] do not come ( as they are considered as unique but actually are same--> remove duplcacy)
         vector<vector<int>> ans;
         vector<int> v;

         combination_helper(candidates, target, v, ans, 0); 
         // 0 is the starting index
        
        //-->Below code works...but takes more time
        //  set<vector<int>>st; //set is a data structure which stores unique values
        //  for(auto e : ans){
        //      st.insert(e);
        //  }
        //  ans.clear(); //clearing ans values
        //  //getting unique values
        //  for(auto e: st){
        //      ans.push_back(e);
        //  }
         return ans;
    }  
};