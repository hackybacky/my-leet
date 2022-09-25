class MyCircularQueue {
public:
    vector<int>my_queue;
    int front , rear;
    int k ;
    MyCircularQueue(int d) {
        my_queue.assign(d , -1);
        k = d;
        front = - 1,
        rear = -1;
    }
    
    bool enQueue(int value) {
        if((rear + 1) % k == front)
            return false;
        if(rear == -1 and front == -1){
            rear = front = 0;
            my_queue[rear] = value;
        }
        else if((rear + 1) % k != front){
        
            rear = (rear + 1)%k;
            my_queue[rear] = value;
        }
        return true;
        
    }
    
    bool deQueue() {
        if( rear == front and front == -1)
            return false;
        else if(rear == front)
        {
            rear = front = -1;
        }
        else
            front = (front + 1)%k;
        return true;
    }
    
    int Front() {
        if(front == -1)
            return -1;
        return my_queue[front];
    }
    
    int Rear() {
        if(rear == -1)
            return -1;
        return my_queue[rear];
    }
    
    bool isEmpty() {
        return front == -1 and front == rear;
    }
    
    bool isFull() {
        return (rear + 1)% k == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */