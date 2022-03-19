class FreqStack {
public:
    map<int,int> freq;
    map<int,stack<int>> mp;
    int maxi =0;
    FreqStack() {
    }
    
    void push(int val) {
        maxi = max(maxi , ++freq[val]);
        mp[freq[val]].push(val);
        
    }
    
    int pop() {
        
        int ans = mp[maxi].top();
        mp[maxi].pop();
        if(mp[maxi].size()==0)maxi--;
        freq[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */