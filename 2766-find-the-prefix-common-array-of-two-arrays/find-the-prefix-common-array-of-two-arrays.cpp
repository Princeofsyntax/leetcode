class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n,0);
        unordered_set<int>mp;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(mp.count(A[i]))count++;
            else mp.insert(A[i]);
            if(mp.count(B[i]))count++;
            else mp.insert(B[i]);
            ans[i] = count;
        }
        return ans;
    }
};