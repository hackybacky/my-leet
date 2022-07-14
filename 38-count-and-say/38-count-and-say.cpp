class Solution {
public:
    string countAndSay(int n) {
        
        string lans="1";
        
        for(int i=1;i<n;i++){
            
            int cnt=1;
            string ans = "";
            char last=lans[0];
            int sz = lans.size();
            for(int j=1;j<sz ; j++){
                if(lans[j]!=last){
                    ans+=to_string(cnt)+(last);
                    last=lans[j];
                    cnt=1;
                }
                else cnt++;
            }
            ans+=to_string(cnt)+(last);
            // cout<<lans<<endl;
            lans = ans;
        }
        return lans;
    }
};