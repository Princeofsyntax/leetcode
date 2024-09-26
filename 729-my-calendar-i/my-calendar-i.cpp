class MyCalendar {
public:
    vector<pair<int, int>>bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& booking : bookings) {
            int bookedStart = booking.first;
            int bookedEnd = booking.second;
            
            if (start < bookedEnd && end > bookedStart) {
                return false;  
            }
        }
        
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */