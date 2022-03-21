class Solution {
public:
    int countCollisions(string s) {
        int ans =0 ;
        
        int n = s.size();
        
        for(int i=0; i<n-1; i++){
            if(s[i]=='R' and s[i+1]=='L')ans+=2,s[i+1]='S',s[i]='S';
            
        }
        int cur =0;
        for(int i=0; i<n; i++){
            if(s[i]=='R')cur++;
            else if(s[i]=='S')ans+=cur,cur=0;
        }
        cur=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='L')cur++;
            else if ( s[i]=='S')ans+=cur,cur=0;
        }
        
        return ans;
    }
};