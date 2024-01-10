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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        //create a dummy node 
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans; //will traverse 

        while(left && right) //till any list become NULL
        {
           if((left->val) <= (right->val)){
               //connection
               mptr->next = left;
               //updation
               mptr = left;
               left = left->next;
           }
           else{
               //connection
               mptr->next = right;
               //updation
               mptr = right;
               right = right->next;
           }
        }
        //link if any list is left and other one is linked already(finished)
        if(left){
            mptr->next = left;
        }
        if(right){
            mptr->next = right;
        }
       return ans->next;

    }
};