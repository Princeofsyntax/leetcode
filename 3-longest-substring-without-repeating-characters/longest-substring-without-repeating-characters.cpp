class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0; // Initialize the variable to store the length of the longest substring
        unordered_map<char, int> lastSeen; // Map to store the last seen index of each character

        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (lastSeen.find(s[i]) != lastSeen.end()) {
                // If the character is already seen in the current substring, update the start of the substring
                j = max(j, lastSeen[s[i]] + 1);
            }
            // Update the last seen index of the character
            lastSeen[s[i]] = i;
            // Update the length of the longest substring
            ans = max(ans, i - j + 1);
        }

        return ans; // Return the length of the longest substring without repeating characters
    }
};
