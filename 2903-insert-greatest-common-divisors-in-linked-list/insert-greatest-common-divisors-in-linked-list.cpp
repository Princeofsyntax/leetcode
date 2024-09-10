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
     int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        if (b == 0) 
            return a; 
        if (a == b) 
            return a; 
    
        if (a > b) 
            return gcd(a - b, b); 
        return gcd(a, b - a); 
    } 

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr){
            ListNode* newNode = new ListNode(gcd(prev->val, curr->val));
            newNode->next = curr;
            prev->next = newNode;
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};