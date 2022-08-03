class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto it = mp.lower_bound(end);
        
        
        if((*it).first==end){
            return false;
        }
        if(it!=mp.begin()){
            auto p = prev(it);
            int pr = (*p).first;
            if(start<pr){
                
                return false;
            }
        }
        
        if(it!=mp.end()){
            auto n = it;
            if(n!=mp.end()){
                // cout<<"hello"<<endl;
                int st = (*n).second;
                if(st<end){cout<<"f"<<endl;return false;}
            }
        }
        mp[end]=start;
        // auto n = next(it);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */