class Solution {
public:
ListNode* reverse(ListNode*head)
{
    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode* temp = head;
    while(curr!=NULL)
    {
        temp = curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* temp=reverse(head);
        int val1=temp->val+temp->val;
        int val2=val1%10;
        int carry=val1/10;
        ListNode* ans=new ListNode(val2);
        ListNode* dummy=ans;
        temp=temp->next;
        while(temp!=NULL)
        {
          int val3=temp->val+temp->val+carry;
          int val4=val3%10;
          carry=val3/10;
          ListNode* temp2=new ListNode(val4);
          ans->next=temp2;
          ans=ans->next;
          temp=temp->next;
        }
        if(carry!=0)
        {
            ListNode* carr=new ListNode(carry);
            ans->next=carr;
        }
        ListNode* newHead = reverse(dummy);
   
    
        return newHead;
    }
};