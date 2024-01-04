class Solution {
public:
    void combination_helper(vector<int>& candidates, int target, vector<int>&v,vector<vector<int>> &ans, int index){
         //base case
         if( target == 0){
             ans.push_back(v);
             return; 
         }
         if( target < 0){
             return;
         }

         //recusrion 
         for(int i = index; i< candidates.size(); i++){
             v.push_back(candidates[i]);
            //checking for same i and for loop is iterating on given array ( as one element can be chosen unlimited time)
             combination_helper(candidates,target-candidates[i], v, ans, i);
             //backtracking
             v.pop_back();
         }
    }
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;

        combination_helper(candidates,target,v,ans,0); //0 is the starting index
        return ans;
    }
};