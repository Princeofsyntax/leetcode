class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int n = words.size();
        set<char>st{'a', 'e', 'i', 'o', 'u'};
        vector<int>helper;
        helper.push_back(0);
        int count = 0;
        for(const auto& word : words){
            if((st.find(word[0]) != st.end()) && (st.find(word[word.size()-1]) != st.end())){
                count++;
            }
            helper.push_back(count);
        }
        // for(auto c:helper)cout<<c<<" ";
        vector<int>ans;
        for(const auto&query : queries){
            ans.push_back(helper[query[1]+1] - helper[query[0]]);
        }
        return ans;
    }
};