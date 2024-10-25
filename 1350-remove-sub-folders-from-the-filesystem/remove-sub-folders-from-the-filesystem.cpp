class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        
        string prev = "";  
        for (const auto& f : folder) {
            if (prev.empty() || f.substr(0, prev.size()) != prev || f[prev.size()] != '/'){
                ans.push_back(f);
                prev = f;  
            }
        }
        
        return ans;
    }
};