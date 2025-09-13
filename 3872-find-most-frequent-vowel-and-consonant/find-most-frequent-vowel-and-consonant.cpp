class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>check(26,0);
        for(const auto& c : s) check[c-'a']++;
        int cons = 0, vow = 0;
        for(int i = 0; i < 26; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20) vow = max(vow, check[i]);
            else cons = max(cons , check[i]);
        }
        return vow + cons;
    }
};