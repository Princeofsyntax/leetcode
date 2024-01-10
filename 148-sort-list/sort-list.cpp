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

    ListNode* findMid(ListNode*& head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast) //till NULL
        {
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    
    ListNode* mergeList(ListNode*&left, ListNode*&right){
        if (left == NULL)
          {
            return right;
            }
        if (right == NULL)
        {
            return left;
        }

        // create a dummy node
        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans; // will traverse

        while (left && right) // till any list become NULL
        {
            if ((left->val) <= (right->val))
            {
                // connection
                mptr->next = left;
                // updation
                mptr = left;
                left = left->next;
            }
            else
            {
                // connection
                mptr->next = right;
                // updation
                mptr = right;
                right = right->next;
            }
        }
        // link if any list is left and other one is linked already(finished)
        if (left)
        {
            mptr->next = left;
        }
        if (right)
        {
            mptr->next = right;
        }
        return ans->next;
        }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        //break linked list in two halves using mid node
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL; //breaking in two parts

        //recursion
        left = sortList(left); //will provide head of sorted left list
        right = sortList(right); //will provide head of sorted right list
        ListNode*ans = mergeList(left,right);
        return ans;
    }
};