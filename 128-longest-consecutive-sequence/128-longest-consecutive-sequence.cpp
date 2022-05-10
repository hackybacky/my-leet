class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        
     //   for(auto it : nums)mp[it]=1;
        
        for(auto it : nums ){
            int cur = it;
            if(mp.find(it)!=mp.end())continue;
            if(mp.find(cur-1)!=mp.end() and mp.find(cur+1)!=mp.end()){
                int maxi = mp[cur+1]+mp[cur-1]+1;
                
                mp[cur]=maxi,mp[cur+mp[cur+1]]=maxi,mp[cur-mp[cur-1]]=maxi;
            }
            else if(mp.find(cur-1)!=mp.end()){
                mp[cur]=mp[cur-1]+1;
                mp[cur-mp[cur-1]]=mp[cur];
            }
            else if(mp.find(cur+1)!=mp.end()){
                mp[cur]=mp[cur+1]+1;
                mp[cur+mp[cur+1]]=mp[cur];
            }
            else mp[cur]=1;
            //  for(auto it : mp){
            //     cout<<it.first<<" "<<it.second<<endl;
            //  }
            // cout<<"hello"<<endl;
        }
        int ans = 0;
       for(auto it: mp)ans=max(it.second,ans);
        return ans;
    }
};