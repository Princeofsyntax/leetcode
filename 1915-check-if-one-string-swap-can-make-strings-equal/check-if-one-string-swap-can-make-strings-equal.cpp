class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> diff;
        for(int x = 0; x < n; x++) {
            if(s1[x] != s2[x]) {
                diff.push_back(x);
            }
        }
        if(diff.size() == 0) return true; 
        if(diff.size() == 2) {
            return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
        }
        return false; 
    }
};