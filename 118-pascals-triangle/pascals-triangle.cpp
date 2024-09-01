class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        ans.push_back({1});
        if(numRows == 1) return ans;
        ans.push_back({1,1});
        if(numRows == 2) return ans;

        int count = 2;
        while(count != numRows){
            vector<int>helper;
            helper.push_back(1);
            vector<int>last = ans.back();

            for(int i = 0; i < last.size()-1; i++){
                 helper.emplace_back(last[i] + last[i+1]);
            }
            helper.push_back(1);
            ans.push_back(helper);
            count++;
        }

        return ans;
    }
};