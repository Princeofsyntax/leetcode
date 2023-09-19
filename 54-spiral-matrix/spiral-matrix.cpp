class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m=matrix.size();  //row
    int n=matrix[0].size();  //column
    int total_elements=m*n;
    int startingRow=0;
    int endingRow=m-1;
    int startingCol=0;
    int endingcol=n-1;
    int count=0;

   while (count<total_elements)
   {
     //printing starting row
     for (int i = startingCol; i <=endingcol && count<total_elements; i++)
     {
        ans.push_back(matrix[startingRow][i]);
        count++;
     }
     startingRow++;

     //printing ending column
     for (int i = startingRow; i <=endingRow && count<total_elements; i++)
     {
        ans.push_back(matrix[i][endingcol]);
        count++;
     }
     endingcol--;

     //printing ending row
     for (int i = endingcol; i >=startingCol && count<total_elements; i--)
     {
        ans.push_back(matrix[endingRow][i]);
        count++;
     }
     endingRow--;

     //printing starting column
     for (int i = endingRow; i >=startingRow && count<total_elements; i--)
     {
        ans.push_back(matrix[i][startingCol]);
        count++;
     }
     startingCol++;
     
   }
   return ans;
    }
};