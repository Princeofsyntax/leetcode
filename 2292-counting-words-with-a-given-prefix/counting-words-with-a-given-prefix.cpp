class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = pref.size();
        for(const auto& word : words){
            if(word.size() < n)continue;
            if(word.substr(0,n) == pref)ans++;
        }
        return ans;
    }
};