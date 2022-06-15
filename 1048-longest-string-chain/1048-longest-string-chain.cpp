class Solution {
public:
    int dp[1001];
    bool isBPredecessorOfA(string &a, string &b) {
        int i = 0;
        // Find first non-matching letter
        for (; i < a.size(); i++) {
            if (a[i] != b[i]) {
                break;
            }
        }
        for (int ai = i, bi = i + 1; ai < a.size(); ai++, bi++) {
            if (a[ai] != b[bi]) {
                return false;
            }
        }
        return true;
    }
    int recur(int i , vector<string>&words ){
        
        if(i==words.size())return 0;
        // cout<<words[i]<<" "<<i<<endl;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        // for(auto it :words)cout<<it<<endl;
    
        for(int j=i+1;j<words.size();j++){
            string nw= words[j];
            string cur = words[i];
            if(nw.size()!=cur.size()+1)continue;
            
            if(isBPredecessorOfA(cur,nw)){
                ans=max(ans,1+recur(j,words));
            }
        }
        return dp[i]=ans;
    }
    static bool cmp(string & a , string & b){
        return a.size()<b.size();
        
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        memset(dp,-1,sizeof(dp));
        int ans=1;
        for(int i=0;i<words.size();i++){
            ans=max(ans,recur(i,words)+1);
        }
        return ans;
    }
};