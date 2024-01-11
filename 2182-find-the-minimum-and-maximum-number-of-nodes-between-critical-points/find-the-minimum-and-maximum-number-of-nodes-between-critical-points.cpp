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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //head and tail will not be counted as they dont have prev or next
        vector<int>ans = {-1,-1}; //{minDistance, maxDistance}
        ListNode* prev = head;
        if(!prev) return ans;  //head is NULL
        ListNode* curr = head->next;
        if(!curr) return ans;  //head->next is NULL
        ListNode* nxt = head->next->next;
        if(!nxt) return ans;  //head->next->next is NULL

        //for maxDist --> diff. btw first and last critical points
        //for minDist --> minimum diff. btw critical points

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;
        int i = 1; //starts from curr point
        while(nxt){
              bool isCP = ((curr->val > prev->val) && (curr->val > nxt->val)) || ((curr->val < prev->val) && (curr->val < nxt->val)) ? true : false;
              if(isCP && firstCP == -1) //first critical point
              {
                   firstCP = i;
                   lastCP = i;
              }
              else if(isCP)
              {
                   minDist = min(minDist, i-lastCP);
                   lastCP = i;
              }
              ++i;
              prev = prev->next;
              nxt = nxt->next;
              curr = curr->next;
        }
        if(lastCP == firstCP){
            //only one CP present
            return ans;
        }
        else{
            ans[0] = minDist;
            ans[1] = (lastCP - firstCP);
        }
       return ans;
    }
};