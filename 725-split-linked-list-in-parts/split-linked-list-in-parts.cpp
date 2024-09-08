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
    int calculateLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>arr(k,nullptr);
        int n = calculateLength(head);
        ListNode* temp = head;
        int i = 0;
        if(n < k){
            while(temp){
               arr[i] = temp;
               temp = temp->next;
               arr[i]->next = nullptr;
               i++;
            }
            return arr;
        }
        int count = n/k;
        int extraCount = n%k;
        temp = head;
        i = 0;
        while(temp){
            arr[i] = temp;
            ListNode* temp2 = arr[i];
            temp = temp->next;
            int currCount = count - 1; 
           while (currCount > 0 && temp) {
                temp2->next = temp;
                temp2 = temp;
                temp = temp->next;
                currCount--;
            }
           if(extraCount && temp){
            temp2->next = temp;
            temp2 = temp;
            temp = temp->next;
            extraCount--;
           }
           temp2->next = nullptr;
           i++;
        }
        return arr;
    }
};