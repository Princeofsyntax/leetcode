class Solution {
public:
    bool closeStrings(string word1, string word2) {
       if(word1.size() != word2.size()) return false;

       unordered_map<char, int>freq1, freq2;
       unordered_set<char>charSet1, charSet2;

       for(const auto&ch : word1){
          freq1[ch]++;
          charSet1.insert(ch);
       }
       for(const auto&ch : word2){
          freq2[ch]++;
          charSet2.insert(ch);
       }
       
       if(charSet1 != charSet2) return false;

       vector<int>helper1,helper2;

       for(const auto&pair : freq1){
           int value = pair.second;
           helper1.push_back(value);
       }
       for(const auto&pair : freq2){
           int value = pair.second;
           helper2.push_back(value);
       }

       sort(helper1.begin(), helper1.end());
       sort(helper2.begin(), helper2.end());

       return helper1 == helper2;
    }
};