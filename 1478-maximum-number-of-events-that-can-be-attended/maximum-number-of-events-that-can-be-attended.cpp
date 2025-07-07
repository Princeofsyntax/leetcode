class Solution {
public:
    static bool compareByEndDay(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }

    int maxEvents(vector<vector<int>>& events){
        int ans = 0;
        int i = 0;
        int n = events.size();
        sort(events.begin(), events.end());//sorting according to start date
        priority_queue<int,vector<int>,greater<int>>pq; //minHeap to push last date
        int lastDate = (*max_element(events.begin(), events.end(), compareByEndDay))[1]; //[1] is tp get last date
        for(int day = 1; day <= lastDate; day++){
            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < day) pq.pop();
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        } 
        return ans;
    }
};