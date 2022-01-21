class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            
        unordered_map<string ,vector<string>> mp;
        
        for(auto it : strs){
            auto t=it;
            sort(t.begin(),t.end());
            
            mp[t].push_back(it);
        }
        vector<vector<string>> lans;
        for(auto it : mp){
            lans.push_back(it.second);
        }
        
        return lans;
        
    }
};