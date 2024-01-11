/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   

    Node* copyRandomList(Node* head) {
       if(head==0) return 0;

       //step1: clone A->A'
       Node* it = head; //iterate over old head

       while(it){
           //cloning nodes
           Node* cloneNode = new Node(it->val);
           cloneNode->next = it->next;
           it->next = cloneNode;
           it = it->next->next;
       }

       //step2: We have to assign random pointing on cloneNodes using oldNodes
       it = head;
       while(it){
           Node* cloneNode = it->next;
           cloneNode->random = it->random ? it->random->next : nullptr; //nullptr means NULL //if case used here
           it = it->next->next;
       }

       //step3: Detach A and A'
       it = head;
       Node* cloneHead = it->next;
       while(it){
           Node* cloneNode = it->next;
           it->next = it->next->next;
           if(cloneNode->next){
               cloneNode->next = cloneNode->next->next;
           }
           it=it->next;
       }
       return cloneHead;
    }
};