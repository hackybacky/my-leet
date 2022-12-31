class Solution {
public:
    int reverse(int x) {
        
        int ans = 0 ;
        int maxi = INT_MAX;
        int mini = INT_MIN;
        int cur = 0;
        while(x ){
            if(cur >= maxi /10 + 1 or cur <= mini / 10 - 1){
                return 0;
            }
            cur = cur * 10 + x % 10;
            x /= 10;
        }
        return cur;
    }
};