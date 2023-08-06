class MyQueue {
public:
    stack<int >sta , stb;

    MyQueue() {
        
    }
    
    void push(int x) {
        sta.push(x);    
    }
    
    void display(){
        while(!sta.empty()){
            stb.push(sta.top());
            sta.pop();
        }
    }
    int pop() {
        if(stb.empty()){
            display();
        }
        int t = stb.top();
        stb.pop();
        return t;
        
    }
    int peek() {
        if(stb.empty())display();
        return stb.top();
    }
    
    bool empty() {
        return stb.empty() and sta.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */