class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> idx; // Create a vector of pairs to store scores and their indices
        
        for (int i = 0; i < n; ++i)
            idx.push_back(make_pair(score[i], i));
        
        // Sort the idx vector in descending order based on scores
        // Uses a lambda function as the comparator for sort()
        sort(idx.begin(), idx.end(),
            [&](const pair<int, int>& x, const pair<int, int>& y) { return x.first > y.first; });
        
        vector<string> ans(n); // Initialize a vector of strings to store ranks
        vector<string> top3 = {"Gold Medal", "Silver Medal", "Bronze Medal"}; // Initialize top 3 medals
        
        // Loop through each pair in the sorted idx vector and assign ranks
        for (int i = 0; i < n; ++i)
            // If index is less than 3, assign the corresponding medal from top3; otherwise, assign the rank converted to a string
            ans[idx[i].second] = i < 3 ? top3[i] : to_string(i + 1);
        
        return ans; // Return the vector containing the ranks
    }
};
