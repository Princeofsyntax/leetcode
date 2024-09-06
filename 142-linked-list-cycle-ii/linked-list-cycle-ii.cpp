/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        
        bool loopPresent = false;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow == fast) {
               loopPresent = true;
               break;
            }

        }
        
        if(loopPresent){
           slow = head;
           while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        }
        
        return loopPresent ? slow : nullptr;
    }
};