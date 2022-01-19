class Solution {
public:
    vector<vector<int>>lans;
    int n;
    void solve(vector<int>& c,vector<int> v,int sum,int k){
        if(sum <0)return ;
        if(sum==0){
            lans.push_back(v);
        }
        
        for(int i=k ; i< n; i++){
            sum-=c[i];
            v.push_back(c[i]);
            solve(c,v,sum,i);
            sum+=c[i];
            v.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        solve(candidates,{},target, 0);
        return lans;
    }
};