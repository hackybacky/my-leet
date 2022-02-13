class Solution {
public:
    int n;
    vector<vector<int>> lans;
    void back(int i,vector<int> &cur,vector<int>&a){
       // if(i>=n){
            lans.push_back(cur);
            
        
        
        for(int k=i; k<n; k++){
            
            cur.push_back(a[k]);
            int j=k;
            int dk=k;
            while(j<n and a[k]==a[j])j++;
            
            back(dk+1,cur,a);
            k=j-1;
            cur.pop_back();
            
           // back(j,cur,a);
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> cur;
        back(0,cur,nums);
        return lans;
    }
};