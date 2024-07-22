class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> helper;
        int n = names.size();

        // Combine heights and names into a single vector of pairs
        for (int i = 0; i < n; i++) {
            helper.emplace_back(std::make_pair(heights[i], names[i]));
        }

        // Sort the helper vector based on heights in descending order
        sort(helper.rbegin(), helper.rend());

        // Prepare the result vector of names
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(helper[i].second);
        }

        return ans;
    }
};