class Solution {
public:
    bool check(char x){
        return !isalnum(x); 
    }

    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;
        
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        bool vowel = false, cons = false;
        
        for(int i = 0; i < n; i++){
            if(check(word[i])) return false;

            if (isalpha(word[i])) {
                if(vowels.count(word[i])) vowel = true;
                else cons = true;
            }
        }
        return vowel && cons;
    }
};
