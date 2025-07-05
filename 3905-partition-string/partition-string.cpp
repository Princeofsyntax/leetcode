class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>mp;
        vector<string>ans;
        int n = s.size();
        string add = "";
        for(int i = 0; i < n; i++){
            add += s[i];
            if(!mp.count(add)){
                ans.push_back(add);
                mp.insert(add);
                add.clear();
            }
        }
        return ans;
    }
};