class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        if(n == 0) return 0;
        set<char>vowel = {'a', 'e', 'i', 'o','u'};
        
        int count = 0;
        int left = 0;
        int right = 0;
        // initial window
        while(right < k && right < s.size()){
            if(vowel.find(s[right]) != vowel.end()){
                count++;
            }
            right++;
        }

        int maxVowel = count;
        
        // sliding window
        while (right < n) {
            if (vowel.find(s[left]) != vowel.end()) {
                count--;
            }
            if (vowel.find(s[right]) != vowel.end()) {
                count++;
            }

            maxVowel = max(maxVowel, count);
            
            right++;
            left++;
        }

        return maxVowel;
    }
};