class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        int n = str1.size();
        int m = str2.size();
        while(i < n){
            if(j == m){
                return true;
            }
            if(str1[i] == str2[j] || (str1[i] + 1 - 'a') % 26 + 'a' == str2[j]){
                j++;
                i++;
            }
            else{
                i++;
            }
        }
         return j == m;
    }
};