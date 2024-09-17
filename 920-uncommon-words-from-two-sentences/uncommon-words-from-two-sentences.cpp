class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>count;
        vector<string>ans;

        auto countWords = [&](string sentence){
           // declare a object for the class stringstream
           stringstream ss(sentence);
           string word;
           // extraction operator (>>), which reads space-separated chunks
           while(ss >> word){
              count[word]++;
           }
        };

        countWords(s1);
        countWords(s2);

        for(const auto& c : count){
            if(c.second == 1){
                ans.push_back(c.first);
            }
        }

        return ans;
    }
};