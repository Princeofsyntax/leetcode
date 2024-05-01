class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        int count = 0;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch ){
                count++;
                if(count == 1){
                    ans += word[i];
                    reverse(ans.begin(), ans.end());
                }
                else{
                    ans += word[i];
                }
            }
            else{
              ans += word[i];
            }
            
        }
        return ans;
    }
};