class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // Initialize the queue (no need to explicitly do anything here)
    }
    
    int ping(int t) {
        // Add the new request timestamp to the queue
        q.push(t);
        
        // Remove timestamps that are outside the 3000 milliseconds window
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // The size of the queue is the number of recent requests
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */