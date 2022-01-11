class Solution {
public:
    int reverse(int x) {
        int res=0;
        int cur=0;
        int p=10;
        while(x){
           // cout<<res<<endl;
            if(res >= 214748365 or  res<=-214748365)return 0;
            int rem=x%10;
            res*=p;
            //cout<<res<<endl;
            res+=rem;
            
            
            x/=10;
            
        }
        return res;
        
    }
};