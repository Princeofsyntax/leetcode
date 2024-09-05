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
    int findLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
           len++;
           temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = findLength(head);
        if(len < k) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward;
        int count = 0;
        while(count < k){
             forward = curr->next;
             curr->next = prev;
             prev = curr;
             curr = forward;
             count++;
        }

        if(forward){
            head->next = reverseKGroup(forward, k);
        }

        return prev;
    }
};