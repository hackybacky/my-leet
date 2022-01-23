class Solution {
public:
    int n;
    bool isvalid(vector<vector<int>> &statements,vector<int> cur){
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(cur[i]==1 and (statements[i][j]!=2 and statements[i][j]!=cur[j]))return false;
            }
        }
        
        return true;
        
    }
    
    // int cal(vector<int> cur){
    //     int ans=0;
    //     for(int i=0; i<16; i++){
    //         if(cur[i]==1)ans++;
    //     }
    //     return ans;
    // }
    int ans=0;
    void solve(vector<vector<int>> &statements,vector<int> cur,int i,int an){
        
        if(i==n){
            if(isvalid(statements,cur)){
                ans=max(ans,an);
                return;
            }
            else{
                return ;
            }
        }
        
        cur[i]=1;
        //ans=0;
        solve(statements,cur,i+1,an+1);
        cur[i]=0;
        solve(statements,cur,i+1,an);
        
        
        
        
    }
    int maximumGood(vector<vector<int>>& statements) {
        n=statements.size();
        ans=0;
        vector<int> cur(n+1,0);
        solve(statements,cur,0,0);
        return ans;
        
    }
};