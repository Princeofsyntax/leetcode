class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int>row(r,0);
        vector<int>col(c,0);
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                mp[mat[i][j]] = {i, j};
            }
        }
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int x = mp[arr[i]].first;
            int y = mp[arr[i]].second;
            if(row[x] == c-1 || col[y] == r-1) return i;
            row[x]++;
            col[y]++;
        }
        return -1;
    }
};