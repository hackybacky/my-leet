class Solution {
public:
    int numberOfWays(string s) {
        long long ans=0;
        const int mod =1e9+7;
        
        int n =s.size();
      //  string s=corridor;
        int cnt=0;
        ans=1;
        int seat=0;
        int j=-1;
        int k=0;
        for(int i=0; i< n ; i++){
            
            if(s[i]=='S'){
                cnt++;
                k++;
                if(k==3){
                    ans=(ans*(i-j))%mod;
                    k=1;
                }
                j=i;
                
            }
        }
       // cnt=count(s.begin(),s.end(),'S');
        if(cnt%2==1 or cnt==0)return 0;
        return ans;
        
    }
};