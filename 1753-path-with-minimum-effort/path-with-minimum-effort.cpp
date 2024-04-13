class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
     {
        //we will solve using graph algo ( djikstra )by using meanHeap(priority queue) so that minimum is automatically fetched
        //first is difference and pair is coordinates
        priority_queue< pair<int,pair<int ,int>>, vector<pair<int,pair<int ,int>>>, greater<pair<int,pair<int ,int>>>>pq; //minHeap 
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX)); //to visualize answer at each cell
        pq.push({0,{0,0}}); //initially
        dist[0][0] = 0;

        while(!pq.empty())
        {
            auto fNode = pq.top();
            pq.pop();
            int frontNodeDiff = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;
            //check is answerr is reached
            if(x == heights.size()-1 && y == heights[0].size()-1)
            {
                //last cell
                return dist[x][y];
            }

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < heights.size() && newY >= 0 && newY < heights[0].size())
                {
                    int currNodeDiff = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDiff, currNodeDiff);
                    if(newMax < dist[newX][newY])
                    {
                        dist[newX][newY] = newMax; //update
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};