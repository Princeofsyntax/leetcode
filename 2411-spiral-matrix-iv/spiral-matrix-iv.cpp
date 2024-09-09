/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));

        ListNode* temp = head;
        if(!temp) return ans;
        int startRow = 0, startCol = 0;
        int endRow = m-1, endCol = n-1;

        while(temp){
           for(int i = startCol; i <= endCol && temp ; i++){
              ans[startRow][i] = temp->val;
              temp = temp->next;
           }
           startRow++;
           for(int i = startRow; i <= endRow && temp ; i++){
               ans[i][endCol] = temp->val;
               temp = temp->next;
           }
           endCol--;
           for(int i = endCol; i >= startCol && temp ; i--){
               ans[endRow][i] = temp->val;
               temp = temp->next;
           }
           endRow--;
           for(int i = endRow; i>= startRow && temp ; i--){
               ans[i][startCol] = temp->val;
               temp = temp->next;
           }
           startCol++;
        }
       return ans;
    }
};