class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        vector<vector<int>>mp(26,vector<int>(26,0));
        
        unordered_map<string,bool>hav;
        for(auto it : ideas)hav[it]=true;
        long long  ans=0;
        set<char>fir;
        for(auto it : ideas)fir.insert(it[0]);
        for(int i=0;i<ideas.size();i++){
            char f = ideas[i][0];
            for(auto it : fir){
                ideas[i][0]=it;
                
                // cout<<cur<<endl;
                if(hav.find(ideas[i])==hav.end() ){
                    // cout<<cur<<endl;
                    ans+=mp[it-'a'][f-'a'];
                    // mp[i][j] means number of words in which i have replaced i with j and not found in hav array 
                    // mp[j][ideas[i][0]-'a']++;
                    mp[f-'a'][it-'a']++;
                }
            }
        }
        ans+=ans;
        return ans;
    }
};