class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        int i = 0, j = 0; 
        string ans = "";
        
        // Merge alternately while both strings have characters
        while (i < n && j < m) {
            ans += word1[i++];
            ans += word2[j++];
        }
        
        // If there are remaining characters in word1
        while (i < n) {
            ans += word1[i++];
        }
        
        // If there are remaining characters in word2
        while (j < m) {
            ans += word2[j++];
        }
        
        return ans;
    }
};