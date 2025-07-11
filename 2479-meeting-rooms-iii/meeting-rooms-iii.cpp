class Solution {
public:
        struct T {
        long endTime;
        int roomId;
    };

    static bool compare(const T& a, const T& b) {
        if (a.endTime == b.endTime)
            return a.roomId > b.roomId;
        return a.endTime > b.endTime;
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n); 
        sort(meetings.begin(), meetings.end());  //sort meetings by start time

        //min-heap for occupied rooms (by end time)
        priority_queue<T, vector<T>, decltype(&Solution::compare)> occupied(Solution::compare);
        
        //min-heap for available room IDs
        priority_queue<int, vector<int>, greater<>> availableRooms;

        for (int i = 0; i < n; ++i) availableRooms.push(i);  //initially all rooms are free

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            //free up rooms whose meetings have ended before current meeting starts
            while (!occupied.empty() && occupied.top().endTime <= start) {
                availableRooms.push(occupied.top().roomId);
                occupied.pop();
            }

            if (availableRooms.empty()) {
                //delay the meeting as no rooms are free and reuse the soonest free room
                T current = occupied.top();
                occupied.pop();
                count[current.roomId]++;
                occupied.push({current.endTime + (end - start), current.roomId});
            } else {
                //assign available room
                int roomId = availableRooms.top();
                availableRooms.pop();
                count[roomId]++;
                occupied.push({end, roomId});
            }
        }
        return max_element(count.begin(), count.end()) - count.begin();
    }
};