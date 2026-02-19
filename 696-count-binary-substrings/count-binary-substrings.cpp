class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        
        int prevGroup = 0;   //length of previous group
        int currGroup = 1;   //length of current group
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                currGroup++;      //same group continues
            } else {
                ans += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }
        //add last pair
        ans += min(prevGroup, currGroup);
        
        return ans;
    }
};