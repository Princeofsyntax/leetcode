class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(!g.size()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();
        int i = 0, j = 0;
        int ans = 0;
        while(i < n && j < m){
            if(g[i] <= s[j]){
                ans++;
                i++;
                j++;
            }
            else{
               j++;
            }
        }
        return ans;
    }
};