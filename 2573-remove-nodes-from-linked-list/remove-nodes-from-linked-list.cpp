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
    ListNode *reverseUsingLoop(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            // updation
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* root = reverseUsingLoop(head); //reversed linked list
        ListNode* curr = root;
        ListNode* nxt = curr->next;

        while(nxt != NULL){
            if(curr->val > nxt->val){
                curr->next = nxt->next;
                nxt->next = NULL;
                nxt = curr->next; 
            }
            else{
                curr = nxt;
                nxt = nxt->next;
            }
        }
       ListNode* root1 = reverseUsingLoop(root);
       return root1;
    }
};