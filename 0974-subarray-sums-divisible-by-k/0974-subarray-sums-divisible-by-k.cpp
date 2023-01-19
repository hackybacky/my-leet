class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        
        map<int , int > mp;
        mp[0] = 1;
        int sum = 0;
        for(auto it : nums){
            sum += it;
            int rem = ((sum )%k + k) % k;
            
            ans += mp[rem];
            cout << mp[rem] << endl;
            mp[rem]++;
        }
        
        return ans;
        
    }
};