class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        int ans =0;
        int on = arr.size();
        int n = on;
        
        vector<int>v;
        
        for(auto it : mp)v.push_back(it.second);
        sort(v.begin(),v.end());
        
        for(int i=v.size()-1;i>=0 ; i--){
            auto cur = v[i];
            n-=cur;
            ans++;
            if(n<=on/2){
                break;
            }
        }
        return ans;
    }
};