class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int>pref(n,0);
        vector<int>suf(n+1,0);
        
        for(int i=1;i<n;i++){
            if(security[i-1]>=security[i]){
                pref[i]+=pref[i-1]+1;
            }
            else{
                pref[i]=0;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i]){
                suf[i]+=suf[i+1]+1;
            }
            else suf[i]=0;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(pref[i]>=time and suf[i]>=time)ans.push_back(i);
        }
        return ans;
    }
};