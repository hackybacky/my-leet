class Solution {
public:
static bool cmp(pair<string,int>a,pair<string,int>b){
    return a.first<b.first or (a.first==b.first and a.second<b.second);
}
int give_ans(int i,vector<string>&nums,int k){
    
    vector<pair<string,int>>v;
    for(auto j=0;j<nums.size();j++ ){
        auto it = nums[j];
        int sz = it.size();
        if(sz-i>=0)
        v.push_back({it.substr(sz-i),j});
    }
    sort(v.begin(),v.end());
    
    return v[k-1].second;
}
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        
        vector<int>ans;
        for(auto it : queries){
           
        
            // cout<<s<<endl;
            ans.push_back(give_ans(it[1],nums,it[0]));
        }
        return ans;
    }
};