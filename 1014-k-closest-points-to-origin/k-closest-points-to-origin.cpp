class Solution {
public:
    class myComp{
        public:
         bool operator()(pair<int,int>&a, pair<int,int>&b){
           int distA = a.first*a.first + a.second*a.second; //finding distance square --> can also be used to compare
           int distB = b.first*b.first + b.second*b.second;
           return distA > distB; //return smaller--> nearest to origin
         }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp>pq; //minHeap

        for(auto p: points){
            pq.push({p[0],p[1]}); //p[0] and p[1] are x,y coordinates
        }

        while(!pq.empty() && k--){
            auto&top = pq.top();
            ans.push_back({top.first, top.second}); //x,y coordinates
            pq.pop();
        }
        return ans;
    }
};