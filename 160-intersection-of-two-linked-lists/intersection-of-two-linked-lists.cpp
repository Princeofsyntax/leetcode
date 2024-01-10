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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a = headA;
        ListNode*b = headB;

        while((a->next != NULL) && (b->next != NULL)){
            if(a == b){
                //when length of both list is same and (a&b) came at same node
                return a;
            }
            a = a->next;
            b = b->next;
        }

        if((a->next  == NULL) && (b->next == NULL) && (a!=b)){
            //we have equal length lists but we didn't find same node
            return NULL;
        }

        //when b length is more or equal
        if(a->next == NULL){
            //find extra length
            int blen = 0;
            while(b->next != NULL){
                blen++;
                b= b->next;
            }
             //shift headB 
             while(blen--){
             headB = headB->next;
            }
        //now both list will have same length after there head
        }

        //when a length is more or equal
        if(b->next == NULL){
            //find extra length
            int alen = 0;
            while(a->next != NULL){
                alen++;
                a= a->next;
            }
             //shift headB 
             while(alen--){
             headA = headA->next;
            }
        //now both list will have same length after there head
        }
      
       //now iterate till intersecting node do not come
       while(headA != headB){
           headA = headA->next;
           headB = headB->next;
       }
       return headA;
    }
};