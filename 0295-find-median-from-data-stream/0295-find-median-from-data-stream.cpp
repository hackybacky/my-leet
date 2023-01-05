class MedianFinder {
public:
    priority_queue<double> low , high;
    int n ;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        
            low.push(-num);
            high.push(num);
            if(high.top() > -low.top()){
                double cur = high.top();
                high.pop();
                high.push(-low.top());
                low.pop();
                low.push(-cur);
            }
        
    }
    
    double findMedian() {
        
        double ans = (high.top() - low.top())/2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */