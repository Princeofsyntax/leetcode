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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }
         //we will work on vector list now
         stack<int> st;
         vector<int> ans(ll.size()); //initiaised all with 0
         
         
         for(int i = 0; i< ll.size(); i++){
             while(!st.empty() && ll[i] > ll[st.top()]) //we will push indices in stack
             {
                //means ith element is the next greater of the elements whoes indices are in stack
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
             }
             st.push(i);
         }
         return ans;
         //time complexity is O(n) as in while loop stack is used -->O(1) & for loop --> O(n)
    }
};