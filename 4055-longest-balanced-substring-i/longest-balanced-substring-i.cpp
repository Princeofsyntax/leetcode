class Solution {
public:

    bool check(vector<int>& chCount) {
        int toMatch = 0;

        for(int i = 0; i < 26; i++) {
            if(chCount[i] != 0) {
                if(toMatch == 0) 
                    toMatch = chCount[i];
                else if(chCount[i] != toMatch)
                    return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            vector<int> chCount(26, 0);

            for(int j = i; j < n; j++) {
                chCount[s[j] - 'a']++;

                if(check(chCount)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};