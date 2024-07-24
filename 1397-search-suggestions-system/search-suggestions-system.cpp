class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        string prefix;
        for (char ch : searchWord) {
            prefix += ch;
            vector<string> suggestions;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                if ((it + i)->substr(0, prefix.size()) == prefix) {
                    suggestions.push_back(*(it + i));
                }
            }
            result.push_back(suggestions);
        }
        return result;
    }
};