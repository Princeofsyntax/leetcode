class MyCircularDeque {
public:
    vector<int> deque;
    int front, rear, capacity, count;
    
    MyCircularDeque(int k) {
        deque.resize(k);
        capacity = k;
        front = 0;
        rear = 0; 
        count = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + capacity) % capacity]; 
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
