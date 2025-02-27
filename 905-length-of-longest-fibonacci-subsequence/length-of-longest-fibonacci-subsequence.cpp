class Solution {
public:
    int helper(int i, int j, vector<int>&arr, unordered_map<int,int>&mp, int length){
        int nextElement = arr[i] + arr[j];
        if(mp.count(nextElement)){
            int k = mp[nextElement];
            return helper(j, k, arr, mp, length+1);
        }
        return length;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++) mp[arr[i]] = i;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int nextElement = arr[i]+arr[j];
                int currLength = 0;
                if(mp.count(nextElement)){
                    currLength = helper(i,j,arr,mp,2); 
                }
                ans = max(ans,currLength);
            }
        }
        return ans;
    }
};