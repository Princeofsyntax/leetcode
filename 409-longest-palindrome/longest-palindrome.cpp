class Solution {
public:
    int longestPalindrome(string s) {
        int charCount[128] = {};

        for (char c : s) {
            charCount[c]++;
        }

        int maxLength = 0; 

        for (int count : charCount) {
            maxLength += count - (count % 2);

           if (maxLength % 2 == 0 && count % 2 == 1) {
                maxLength++;
            }
        }

       return maxLength;
    }
};