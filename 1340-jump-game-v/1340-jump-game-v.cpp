class Solution {
public:
    vector<int> dp;
    int n;
    int d;
    int recur(int i ,vector<int>&arr){
        
        int j=i+1;
        int ans=0;
       // cout<<i<<endl;
        if(dp[i]!=-1)return dp[i];
        while(j<= min(i+d,n-1) and arr[i]>arr[j]){
            ans=max(1+recur(j,arr),ans);
            j++;
        
        }
        j=i-1;
        int anss=-1e9;
        while(j>=max(i-d,0) and arr[i]>arr[j]){
            anss=max(1+recur(j,arr),anss);
            j--;
        }
        return dp[i]=max(ans,anss);
        
        
        
    }
    
    int maxJumps(vector<int>& arr, int dd) {
        n=arr.size();
        dp.assign(n,-1);
        d=dd;
       // recur(0,arr);
        int ans=0;
        for(int i=0 ; i< n ; i++){
            recur(i,arr);
           
        }
        for(int i=0; i<n; i++){
           ans=max(ans,dp[i]);
        }
        return 1+ans;
    }
};