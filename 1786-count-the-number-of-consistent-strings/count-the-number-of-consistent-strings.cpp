class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st(allowed.begin(), allowed.end());
        
        int count = 0;
        int ans = 0;
        for(const auto& word : words){
            int x = word.size();
            for(const auto& ch : word){
                if(st.find(ch) != st.end()){
                    count++;
                }
            }
            if(count == x)ans++;
            count = 0;
        }
        return ans;
    }
};