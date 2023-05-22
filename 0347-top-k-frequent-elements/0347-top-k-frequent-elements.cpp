class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int,int> hash;
        
        for(auto it : nums ){
            hash[it]++;
        }
        
        for(auto it : hash){
            freq[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=n; i>=0; i--){
            for(auto it : freq[i]){
                if(k>0)
                ans.push_back(it),
                k--;
                else goto next;
            }
        }
        next:;
        return ans;
    }
};