class Solution {
public:
    int helper(string &s, set<string>&st, int start){
        if(start == s.size())return 0;

        int count = 0;
        string current = "";
        for(int i = start ; i < s.size(); i++){
            current += s[i];
            if(st.find(current) == st.end()){
                st.insert(current);
                int ans = 1 + helper(s, st, i+1);
                count = max(count, ans);
                st.erase(current);
            }
        }
        return count;
    }

    int maxUniqueSplit(string s) {
        set<string>st;
        return helper(s, st, 0);
    }
};