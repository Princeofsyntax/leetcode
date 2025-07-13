class Solution {
public:
    string processStr(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                if(!ans.empty()) ans.pop_back();
            }
            else if(s[i] == '#'){
                if(!ans.empty()) ans += ans;
            }
            else if(s[i] == '%'){
                if(!ans.empty()) reverse(ans.begin(), ans.end());
            }
            else ans += s[i];
        }
        return ans;
    }
};