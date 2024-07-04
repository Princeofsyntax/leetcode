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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newLastNode = 0;

        int sum = 0;
        while(fast){
            if(fast->val != 0){
                sum += fast->val;
            }
            else{
                //fast->val == o
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }
        ListNode* temp = newLastNode->next;
        newLastNode->next = 0; //to create new Linked list

        //Deleting old list
        while(temp){
            //till last node we have to delete
            ListNode* nxt = temp->next;
            delete temp; //tp avoid memory leak
            temp = nxt; 
        }
        return head;
    }
};