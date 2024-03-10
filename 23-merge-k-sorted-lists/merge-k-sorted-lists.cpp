
class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;
        
        int k = lists.size();
        if(k == 0) return NULL;

        //insert first element of every linked list into minHeap
        for(int i = 0; i < k; i++){
            if( lists[i] != NULL){
                minHeap.push(lists[i]); //pointer is inserted directly (head)
            }
        }
        
        //to be returned at last is head
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            //temp may or may not be the first element of answer linked list
            if(head == NULL){
                //temp--> fist element of LL
                head = tail = temp;
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
            else{
                //temp--> is not the first element of LL
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};