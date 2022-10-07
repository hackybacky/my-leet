class MyCalendarThree {
public:
    map<int , int >mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int fans = 0 ;
        int ans = 0;
        for(auto it : mp){
            ans += it.second;
            fans = max(ans , fans);
        }
        return fans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */