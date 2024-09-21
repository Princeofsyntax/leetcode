class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string word;
        string ans = "";
        stack<string>helper;
        while(st >> word){
            helper.push(word);
        }
        while(!helper.empty()){
            ans+=helper.top() + " ";
            helper.pop();
        }
        if(!ans.empty()){
            ans.pop_back();
        }
        return ans;
    }
};