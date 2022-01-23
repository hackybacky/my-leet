class Solution {

public:
   // int n;
    bool isvalid(vector<vector<int>> &statements,string cur){
        int  n=statements.size();
        for(int i=0 ; i<n ; i++){
            if(cur[i]=='1'){
                for(int j=0 ; j<n ; j++){
                    if(statements[i][j]!=2 and statements[i][j]!=cur[j]-'0')return false;
                }
            }
        }
        
        return true;
        
    }
    
    
    int ans=0;
    void solve(vector<vector<int>> &statements,string cur,int i,int an){
        
        if(i== statements.size()){
            if(isvalid(statements,cur))
                ans=max(ans,an);
            return;
           
        }
        
        cur.append(1, '0');
        solve(statements, cur, i+1, an);        // assuming ith person is bad
        cur.back() = '1';
        solve(statements, cur, i+1, an + 1);    // assuming ith person is good
        cur.pop_back();       
        
        
    }
    int maximumGood(vector<vector<int>>& statements) {
       
        ans=0;
       
        string cur;
        solve(statements,"",0,0);
        return ans;
        
    }
};