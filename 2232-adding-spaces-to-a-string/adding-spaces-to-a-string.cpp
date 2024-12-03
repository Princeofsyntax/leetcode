class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = spaces.size();
        int m = s.size();
        int k = 0;
        for(int i = 0; i < m; i++){
            if(k < n && spaces[k] == i){
                ans += " ";
                ans += s[i];
                k++;
            }
            else{
               ans += s[i];
            }
        }
        return ans;
    }
};