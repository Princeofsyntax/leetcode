class MyCalendarTwo {
public:
    vector<pair<int,int>>singleBooking;
    vector<pair<int,int>>doubleBooking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(const auto & pair : doubleBooking){
            int doubleStart = pair.first;
            int doubleEnd = pair.second;
            if(start < doubleEnd && doubleStart < end){
                return false;
            }
        }

        for(const auto& pair : singleBooking){
            int singleStart = pair.first;
            int singleEnd = pair.second;
            if(start < singleEnd && singleStart < end){
                int newStart = max(singleStart, start);
                int newEnd = min(singleEnd, end);
                doubleBooking.push_back({newStart, newEnd});
            }
        }

        singleBooking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */