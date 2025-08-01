class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)return {{1}};
        if(numRows == 2)return {{1},{1,1}};
        vector<vector<int>>ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i = 3; i <= numRows; i++){
            vector<int>temp1;
            temp1.push_back(1);
            vector<int>temp2 = ans.back();
            for(int j = 0; j < temp2.size()-1; j++){
                temp1.push_back(temp2[j] + temp2[j+1]);
            }
            temp1.push_back(1);
            ans.push_back(temp1);
        }
        return ans;
    }
};