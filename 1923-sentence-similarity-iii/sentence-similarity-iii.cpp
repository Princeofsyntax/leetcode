class Solution {
public:
    vector<string> helper(string &sentence){
        stringstream ss(sentence);
        vector<string>ans;
        string word;
        while(ss >> word){
            ans.push_back(word);
        }
        return ans;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>vec1 = helper(sentence1);
        vector<string>vec2 = helper(sentence2);

        if(vec1.size() < vec2.size()){
            swap(vec1, vec2);
        }

        int i = 0;
        while(i < vec2.size() && vec1[i] == vec2[i]) i++;

        int j = 0;
        while (j < vec2.size() && vec1[vec1.size() - 1 - j] == vec2[vec2.size() - 1 - j]) j++;

         return i+j >= vec2.size();
    }
};