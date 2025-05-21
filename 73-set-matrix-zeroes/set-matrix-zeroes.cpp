class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>cd;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    cd.emplace_back(i, j);
                }
            }
        }

        for(const auto& pair : cd){
            int x = pair.first;
            int y = pair.second;

            for(int j = 0; j < matrix[0].size(); j++){
                matrix[x][j] = 0;
            }

            for(int i = 0; i < matrix.size(); i++){
                matrix[i][y] = 0;
            }
        }
    }
};