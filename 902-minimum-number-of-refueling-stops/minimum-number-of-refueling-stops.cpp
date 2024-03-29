class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int,int>>pq; //maxHeap --> {fuel, position}
        while(true){
          while(i < stations.size()){
              //push stations within the reach with my current fuel level from my current position
              if(stations[i][0] <= dist+fuel){
                  pq.push({stations[i][1], stations[i][0]}); //{fuel,positions}
              }
              else{
                  break;
              }
              ++i;
          }
          
          //travel with full fuel level
          dist += fuel;
          fuel = 0;
          //reached
          if(dist >= target) break;

           //no fuel stations within reach
           if(pq.empty()){
               stops = -1;
               break;
           }
          
          //refuel and re-adjust dist and fuel based on the distance travelled and fuel used till that station
          auto &top = pq.top();
          fuel = (dist - top.second) + top.first;
          dist =  top.second;
          pq.pop();
          ++stops;
        }

        return stops;
    }
};