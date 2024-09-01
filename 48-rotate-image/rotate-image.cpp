class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
          int n = matrix.size();

          // Firstly take transpose 
          for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    break;
                }
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        for(int i = 0; i < n; i++){
            int l = 0;
            int r = n-1;

            while(l < r){
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--; 
            }
        }
    }
};