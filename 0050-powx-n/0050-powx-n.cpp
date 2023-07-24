class Solution {
public:
    
    
    double myPow(double x, int n) {
        if(n==0)return 1.0;
        if(n==1)return x;
        if(n==-1)return 1/x;
        
        double cur=myPow(x,n/2);
        cur*=cur;
        if(abs(n)%2==1){
            if(n<0)cur*=(1.0/x);
            else cur*=x;
        }
        
        return cur;
    }
};