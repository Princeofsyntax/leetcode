class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;                     // Initialize the answer variable
        
        int prefix = 0;                        // Represents the current binary prefix
        vector<int> count(1024);               // Stores the count of occurrences of each binary prefix
        count[0] = 1;                          // Initialize count of empty string ""

        // Iterate through each character in the input string
        for (const char c : word) {
            // Update the binary prefix based on the current character
            prefix ^= 1 << (c - 'a');
            
            // Add the count of substrings with the current prefix to the answer
            ans += count[prefix];
            
            // Iterate over all possible toggled bits and add the count of substrings with those prefixes to the answer
            for (int i = 0; i < 10; ++i)
                ans += count[prefix ^ (1 << i)];
            
            // Increment the count of the current prefix
            ++count[prefix];
        }

        // Return the final answer
        return ans;
    }
};
