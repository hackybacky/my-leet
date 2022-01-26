class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> cnt;
        
        for(auto it :nums){
            if(cnt[it]!=0)return true;
            else cnt[it]++;
        }
        return false;
        
    }
};