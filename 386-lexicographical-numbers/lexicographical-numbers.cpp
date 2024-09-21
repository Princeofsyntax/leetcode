class Solution {
public:
    void helper(int current, int n, vector<int>&ans){
        if(current > n) return;
        ans.push_back(current);

        for(int i = 0; i <= 9; i++){
            if(current*10 + i > n)break;
            helper(current*10 + i,n,ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>ans;

        for(int i = 1; i <= 9; i++){
            if(i > n) break;
            helper(i,n, ans);
        }
        return ans;
    }
};