class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<int>a;
        for(auto &it : words){
            map<int,int> cnt;
            for(auto i : it){
                cnt[i-'a']++;
            }
            
            int mask=0;
            for(int i=0 ; i< 26 ; i++){
                if(cnt[i])
                mask|=(1<<i);
            }
            a.push_back(mask);
            
        }
        int ans=0;
        int n = words.size();
        for(int i=0 ; i< n ; i++){
            for(int j=0; j < n ; j++){
                
                if((a[i] & a[j])==0){
                    // cout<<"helo"<<endl;
                    ans=max(ans, (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return ans;
    }
};