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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = nullptr;

        while(fast != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
            }
        }

        // Delete the middle node
        if (prev != nullptr) {
            prev->next = slow->next;
            delete slow;
        }

        return head;
    }
};