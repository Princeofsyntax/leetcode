class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        vector<unordered_set<int>> lang_sets(m);
        for (int i = 0; i < m; ++i) {
            lang_sets[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        unordered_set<int> problem_users;
        for (const auto& f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            
            bool can_communicate = false;
            
            auto& smaller_set = lang_sets[u].size() < lang_sets[v].size() ? lang_sets[u] : lang_sets[v];
            auto& larger_set = lang_sets[u].size() < lang_sets[v].size() ? lang_sets[v] : lang_sets[u];

            for (int lang : smaller_set) {
                if (larger_set.count(lang)) {
                    can_communicate = true;
                    break;
                }
            }
            
            if (!can_communicate) {
                problem_users.insert(u);
                problem_users.insert(v);
            }
        }
        
        if (problem_users.empty()) {
            return 0;
        }
        
        vector<int> lang_counts(n + 1, 0);
        for (int user_idx : problem_users) {
            for (int lang : lang_sets[user_idx]) {
                lang_counts[lang]++;
            }
        }
        
        int max_speakers = 0;
        for (int l = 1; l <= n; ++l) {
            if (lang_counts[l] > max_speakers) {
                max_speakers = lang_counts[l];
            }
        }
        
        return problem_users.size() - max_speakers;
    }
};