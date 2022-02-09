class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        for(auto it : nums){
            m[it]++;
        }
        
        int cnt=0;
        
        for(auto it : m ){
            if(k==0 and it.second>1)cnt++;
            else if ( k>0 and m.count(it.first+k))cnt++;
        }
        return cnt;
    }
};