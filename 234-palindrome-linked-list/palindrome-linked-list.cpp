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
    ListNode* findMid(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast){
           slow = slow->next;
           fast = fast->next;
           if(!fast) continue;
           fast = fast->next;
        }
        return slow;
    }

    ListNode* reversee(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* temp = nullptr;
        head->next = nullptr;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        if(!head->next) return true;

        ListNode* mid = findMid(head);
        ListNode* temp2 = reversee(mid);
        ListNode* temp1 = head;
        while(temp2){
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};