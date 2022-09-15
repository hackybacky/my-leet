class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        unordered_map<int , int> mp;
        vector<int>ans;
        for(auto it : changed)mp[it]++;
        sort(changed.begin() , changed.end());
        for(auto it : changed){
            if(mp[it] > 0){
                mp[it]--;
                int x = 2*it;
                if(mp[x] <=0 )return {};
                mp[x]--;
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};