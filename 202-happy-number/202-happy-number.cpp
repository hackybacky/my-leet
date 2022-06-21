class Solution {
public:
    int givesum(int n ){
        int su=0;
        while(n){
            su+=(n%10)*(n%10);
            n/=10;
        }
        return su;
    }
    bool isHappy(int n) {
        
        int slow = n;
        int fast=slow;
        while( slow !=1 and fast!=1){
            
            slow=givesum(slow);
            // cout<<slow<<endl;
            fast=givesum(fast);
            fast=givesum(fast);
            if(slow==fast)break;
        }
        return fast==1 or slow==1;
    }
};