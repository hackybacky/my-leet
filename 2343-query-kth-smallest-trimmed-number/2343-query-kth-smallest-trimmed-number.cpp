class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        unordered_map<int,vector<pair<string,int>>>mp;
        
        unordered_map<string,int>indi;
        for(int j=0;j<nums.size();j++){
            string it=nums[j];
            int sz = it.size();
            string t="";
            for(int i=sz-1;i>=0 ; i--){
                t=it[i]+t;
                
                 mp[sz-i].push_back({t,j});
            }
        }
        
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
        vector<int>ans;
        for(auto it : queries){
            int s = mp[it[1]][it[0]-1].second;
        
            // cout<<s<<endl;
            ans.push_back(s);
        }
        return ans;
    }
};