
class MedianFinder {
public:
    priority_queue<int>small,large;
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        small.push(-num);
        large.push(num);
        
        if(large.top()>-small.top()){
            int t = -small.top();
            small.pop();
            small.push(-large.top());
            large.pop();
            large.push(t);
        }
    }
    
    double findMedian() {
       
        double ans = (large.top()*1.0-small.top()*1.0)/(2.0);
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */