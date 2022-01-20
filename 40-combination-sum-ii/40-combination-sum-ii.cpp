class Solution {
public:
    vector<vector<int>> lans;
    int n;
    void solve(vector<int>& a,int target,int i,vector<int> ans){
        if(target<0){
            return ;
        }
        if(target==0){
            lans.push_back(ans);
        }
        for(int k=i ; k<n ; k++){
            
            if(k>i and k-1>=0 and a[k]==a[k-1])continue;
            target-=a[k];
            ans.push_back(a[k]);
            solve(a,target,k+1,ans);
            target+=a[k];
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin() ,candidates.end());
        solve(candidates,target,0,{});
        return lans;
    }
};