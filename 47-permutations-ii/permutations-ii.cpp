class Solution {
public:
    void permuteUniqueHelper(vector<int>& arr,vector<vector<int>>&ans, int start){
       //base case
        if( start == arr.size()){
            ans.push_back(arr);
            return;
        }
        
        unordered_map<int,bool>visited;
        for(int i = start; i<arr.size();i++){
            if(visited.find(arr[i]) != visited.end()){
                //if one time swapping is already done then we will not do swapping again
                continue;
            }
            //mark in visited
            visited[arr[i]] = true;
            swap(arr[i], arr[start]);
            permuteUniqueHelper(arr,ans,start+1);
            //backtracing
            swap(arr[i],arr[start]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& arr) {
       vector<vector<int>>ans;
       permuteUniqueHelper(arr,ans,0); 
    //we can use set-->stores unique values (METHOD 1)
    //    set<vector<int>>mediator;
    //    for(auto e:ans){
    //        mediator.insert(e);
    //    }
    //    //Fetch in ans vector again from set
    //    ans.clear();
    //    for(auto e:mediator){
    //        ans.push_back(e);
    //    }
    //METHOD 2 (try to stop recursion when same call comes i.e, same permutation arise at any level) --> using map
       return ans;
    }
};