class Solution {
public:
    vector<pair<int,int>> getMinPrevNumWithIndices(vector<int>&gridRow){
        vector<pair<int,int>>ans; //{number, index}

        for(int i = 0; i < gridRow.size(); i++){
            ans.push_back({gridRow[i],i});
        }
        sort(ans.begin(), ans.end());

        return {ans[0],ans[1]}; //this will return first minimum and second minimum with indices
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        //we will use dp here
        int n = grid.size();

        for(int i = 1; i < n; i++){
            //we need minimum and second minimum of previous row with there idices
            vector<pair<int, int>>minPreviousTwoNumbers = getMinPrevNumWithIndices(grid[i-1]);
            auto firstMin = minPreviousTwoNumbers[0].first;
            auto firstMinIndex = minPreviousTwoNumbers[0].second;
            auto secondMin = minPreviousTwoNumbers[1].first;

            for(int j = 0; j < grid[0].size(); j++){
                //if current block value column is same as previous firstMinimum value index column then we will add to second Minimum
                //This is because we do not need same column
                if(j == firstMinIndex){
                    grid[i][j] += secondMin;
                }
                else{
                    grid[i][j] += firstMin;
                }
                //after the updation of row, the i loop will execute and will again pick minimum-->so last row minimum value will be the answer
            }
        }
         vector<int>lastRow = grid.back();
         auto ans = *min_element(lastRow.begin(), lastRow.end());
         return ans;
    }
};