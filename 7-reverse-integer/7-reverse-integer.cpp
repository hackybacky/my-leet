class Solution {
public:
    int reverse(int x) {
        long res=0;
        int cur=0;
        int p=10;
        while(x){
            int rem=x%10;
            res*=p;
            cout<<res<<endl;
            res+=rem;
            
            
            x/=10;
            if(res>INT32_MAX or res<INT32_MIN)return 0;
        }
        return res;
        
    }
};