class Solution {
public:
    int scoreOfString(string s) {
        int ans =0;
        int n = s.size();
        for(int i = 0; i < n-1 ; i++){
            char a1 = s[i] + 'a';
            char a2 = s[i+1] + 'a';
            ans += abs(a1 - a2);
        }
        return ans;
    }
};