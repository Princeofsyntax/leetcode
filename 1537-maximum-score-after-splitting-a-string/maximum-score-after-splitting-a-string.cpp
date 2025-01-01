class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0;
        for (const auto& num : s) if (num == '1') ones++;
        int maxScore = 0;
        int leftZeros = 0;   
        int rightOnes = ones; 
        for (int i = 0; i < s.size() - 1; i++) { 
            if (s[i] == '0')leftZeros++;
            else rightOnes--;
            int score = leftZeros + rightOnes;
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};