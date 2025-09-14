class Solution {
public:
    string toLower(const string &s) {
        string res = s;
        for (auto &ch : res) ch = tolower(ch);
        return res;
    }

    string maskVowels(const string &s) {
        string res = toLower(s);
        for (auto &ch : res) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ch = '*';
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelMasked;

        //Preprocessing wordlist
        for (const string &word : wordlist) {
            string wordLower = toLower(word);
            string wordVowelMasked = maskVowels(word);

            //Only store first occurrence for precedence
            if (!caseInsensitive.count(wordLower))
                caseInsensitive[wordLower] = word;
            if (!vowelMasked.count(wordVowelMasked))
                vowelMasked[wordVowelMasked] = word;
        }

        vector<string> ans;
        for (const string &query : queries) {
            // 1. Exact match (case-sensitive)
            if (exactWords.count(query)) {
                ans.push_back(query);
                continue;
            }
            // 2. Case-insensitive match
            string queryLower = toLower(query);
            if (caseInsensitive.count(queryLower)) {
                ans.push_back(caseInsensitive[queryLower]);
                continue;
            }
            // 3. Vowel error match
            string queryVowelMasked = maskVowels(query);
            if (vowelMasked.count(queryVowelMasked)) {
                ans.push_back(vowelMasked[queryVowelMasked]);
                continue;
            }
            // 4. No match
            ans.push_back("");
        }
        return ans;
    }
};