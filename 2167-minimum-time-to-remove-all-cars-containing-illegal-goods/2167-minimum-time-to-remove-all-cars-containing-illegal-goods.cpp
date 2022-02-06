class Solution {
public:
    
    int minimumTime(string s) {
       int res;
        int n=s.size();
        vector<int>right(n+1,0);
        for(int i=n-1; i>=0; i--){
            right[i]=min(right[i+1]+2*(s[i]=='1'),n-i);
        }
        int left=0;
        res=n;
        for(int i=0 ;i<n ; i++){
            if(s[i]=='1')
                left=min(i+1,left+2);
            res=min(res,left+right[i]);
        }
        return res;
    }
};