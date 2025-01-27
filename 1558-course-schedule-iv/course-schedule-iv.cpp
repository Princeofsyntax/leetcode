class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = prerequisites.size();
        int m = queries.size();
        vector<bool>ans(m,false);
        if(n==0)return ans;
        // first approach is to make dfs call for each querry to get if it is prerequisite
        // second approach is to use floydd warshall to prepare for each querry --> used for large number of querries
        vector<vector<int>> helper(numCourses, vector<int>(numCourses, INT_MAX / 2)); // Use INT_MAX / 2 to avoid overflow

        for(const auto& pre : prerequisites){
            helper[pre[0]][pre[1]] = 1;
        }

        for(int i = 0; i < numCourses; i++)helper[i][i] = 0;// no-self-loop

        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (helper[i][k] + helper[k][j] < helper[i][j]) {
                        helper[i][j] = helper[i][k] + helper[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            const auto& q = queries[i];
            if (helper[q[0]][q[1]] != INT_MAX / 2) {
                ans[i] = true; 
            }
        }
        return ans;
    }
};