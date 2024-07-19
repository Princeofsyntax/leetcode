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
    int pairSum(ListNode* head) {
        if (!head) return 0;
        
        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Calculate twin sums and find the maximum
        int maxSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf) {
            int sum = firstHalf->val + secondHalf->val;
            maxSum = max(maxSum, sum);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxSum;
    }
};