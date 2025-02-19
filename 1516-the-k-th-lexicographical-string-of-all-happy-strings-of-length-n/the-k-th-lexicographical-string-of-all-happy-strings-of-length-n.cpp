class Solution {
public:
    void backtrack(int n, string current, vector<string>&happy){
        if(current.size() == n){
            happy.push_back(current);
            return;
        }
        for(char ch : {'a', 'b', 'c'}){
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                backtrack(n, current, happy);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string>happy;
        string current;
        backtrack(n,current,happy);
        if(k > happy.size()){
            return "";
        }
        return happy[k-1];
    }
};