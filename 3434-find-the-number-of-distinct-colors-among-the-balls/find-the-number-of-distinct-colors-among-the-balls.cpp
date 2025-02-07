class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_set<int> distinctColors;
        vector<int> result;
        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            if (ballColor.find(x) != ballColor.end()) {
                int oldColor = ballColor[x];
                bool isOldColorUsed = false;
                for (const auto& pair : ballColor) {
                    if (pair.second == oldColor && pair.first != x) {
                        isOldColorUsed = true;
                        break;
                    }
                }
                if (!isOldColorUsed) {
                    distinctColors.erase(oldColor);
                }
            }
            ballColor[x] = y;
            distinctColors.insert(y);
            result.push_back(distinctColors.size());
        }
        return result;
    }
};