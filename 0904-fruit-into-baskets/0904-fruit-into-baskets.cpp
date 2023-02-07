class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int> mp;
        int n = fruits.size();
        int ans = INT_MIN;
        int l = 0 , r = 0;
        while(r < n ){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)mp.erase(fruits[l]);
                l++;
            }
            // else{
                // ans = max(ans , r - l + 1);
                r++;
            
        }
        return r - l;
        
        
    }
};