class Solution {
public:
    int minDeletions(string s) {
        
        map<char,int>mp;
        for(auto it : s)mp[it]++;
        map<int,int> freq;
        
        for(auto it : mp){
            freq[it.second]++;
        }        
        int ans=0;
        int cur = (*(freq.rbegin())).first;
        cout<<cur<<endl;
        for(auto it =freq.rbegin();it!=freq.rend();it++){
            
            int f =(*it).first;
            int cnt = (*it).second;
            while(cur>0 and cnt>1){
                if(freq.find(cur)==freq.end() and cur<f){
                    ans+=(f-cur);
                    cnt--;
                }
                cur--;
            }
            ans+=(cnt-1)*f;
            
        }
        return ans;
        
    }
};