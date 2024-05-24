class Solution {
public:
     int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int letterCounts[26] = {0}; // Array to hold counts of each letter in 'letters'
        // Count the occurrence of each letter in 'letters'
        for (char& letter : letters) {
            letterCounts[letter - 'a']++; // Increment the count for the corresponding letter
        }

        int numWords = words.size(); // Total number of words
        int maxScore = 0; // Variable to store the maximum score

        // Loop through all combinations of words
        for (int combination = 0; combination < (1 << numWords); ++combination) {
            int wordCounts[26] = {0}; // Current letter counts for the current combination of words
            // Build the count for the current combination
            for (int wordIndex = 0; wordIndex < numWords; ++wordIndex) {
                // Check if the word at wordIndex is included in the current combination
                if (combination >> wordIndex & 1) {
                    // If so, count each letter in the word
                    for (char& letter : words[wordIndex]) {
                        wordCounts[letter - 'a']++; // Increment the count for the corresponding letter
                    }
                }
            }

            bool isValidCombination = true; // Flag to check if the combination is valid
            int currentScore = 0; // Score for the current combination
            for (int letterIndex = 0; letterIndex < 26; ++letterIndex) {
                // If any letter count exceeds what is available, the combination is invalid
                if (wordCounts[letterIndex] > letterCounts[letterIndex]) {
                    isValidCombination = false;
                    break; // No need to continue if the combination is invalid
                }
                // Calculate score for the current combination
                currentScore += wordCounts[letterIndex] * score[letterIndex];
            }

            // If the combination is valid and the score is higher than the maximum found so far, update maxScore
            if (isValidCombination && maxScore < currentScore) {
                maxScore = currentScore;
            }
        }
        // Return the maximum score possible with the given words and letters
        return maxScore;
    }
};