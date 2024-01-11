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
    Node* helper(Node*&head, unordered_map<Node*, Node*>&mp){
        if(head == 0) return 0;
        
        //solve one case and recursion
        Node*newHead = new Node(head->val);
        mp[head]= newHead; //mapping
        newHead->next = helper(head->next, mp);
        //till here linear list copy is made, random pointing is left
        
        if(head->random){
            newHead->random = mp[head->random];
        }
        return newHead; 
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp; //to store old and new nodes for mapping to use while random connections
        return helper(head, mp);
    }
};