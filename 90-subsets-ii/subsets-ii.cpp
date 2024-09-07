class Solution {
public:
    void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index + 1, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set < vector < int >> res;
        vector < int > ds;
        fun(nums, 0, ds, res);
        vector < vector < int >> ans(res.begin(), res.end());
        return ans;
  }
};