class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end()); //sorting lexicographically
        vector<string>result;
        result.push_back(folder[0]);
        for (int i = 1; i < folder.size(); ++i) {
            const string& parent = result.back();
            const string& current = folder[i];
            string parent_prefix = parent + "/";
                
            //The string::rfind(prefix, 0) == 0 is a C++ idiom to check for a prefix.
            if (current.rfind(parent_prefix, 0) != 0) {
                result.push_back(current);
            }
        }
        return result;
    }
};