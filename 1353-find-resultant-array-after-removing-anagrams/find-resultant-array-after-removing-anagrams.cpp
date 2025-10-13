class Solution {
public:
    bool check(string word1, string word2){
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        return word1 == word2 ;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        if(n==1) return words;
        stack<string>st;
        st.push(words[0]);
        int i = 1;
        while(i < n){
            if(check(st.top(), words[i])) i++;
            else{
                st.push(words[i]);
                i++;
            }
        }
        vector<string>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};