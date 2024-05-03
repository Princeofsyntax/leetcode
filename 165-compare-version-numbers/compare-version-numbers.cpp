class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1Length = version1.size(), v2Length = version2.size(); // Store the sizes of both version strings

        // Iterate over both version strings
        for (int i = 0, j = 0; i < v1Length || j < v2Length; ++i, ++j) {
            int num1 = 0, num2 = 0; // Initialize version segment numbers for comparison

            // Parse the next version segment from 'version1'
            while (i < v1Length && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0'); // Convert char to int and accumulate
                ++i; // Move to the next character
            }

            // Parse the next version segment from 'version2'
            while (j < v2Length && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0'); // Convert char to int and accumulate
                ++j; // Move to the next character
            }

            // Compare the parsed version segments
            if (num1 != num2) {
                return num1 < num2 ? -1 : 1; // Return -1 if 'version1' is smaller, 1 if larger
            }
        }

        // If we get to this point, the versions are equal
        return 0;
    }
};