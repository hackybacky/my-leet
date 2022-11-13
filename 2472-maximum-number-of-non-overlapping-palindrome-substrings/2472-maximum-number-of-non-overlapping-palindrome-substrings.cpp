class Solution {
public:
    vector<vector<int>> pal;
    
    int isPal(string &s , int i , int j ){
        if(i > j){
            return 1;
        }
        if(pal[i][j] != -1){
            return pal[i][j];
        } 
        int flag = 1;
        if(s[i] != s[j]){
            flag = 0;
        }
        else{
            flag &= isPal(s , i +1 , j - 1);
        }
        
        isPal(s , i + 1, j);
        isPal(s , i ,  j - 1);
        return pal[i][j] = flag;
    }
    vector<int> dp;
    int K;
    int recur(int i , string & s){
        if( i == s.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = recur(i + 1 , s);
        
        for(int j = i ; j < s.size() ; j++){
            int Palin = pal[i][j];
            
            if(Palin and (j - i + 1) >= K){
                ans =max( 1 + recur(j + 1 , s) , ans);
            }
        }
        return dp[i] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        K = k;
        pal.assign(n + 1, vector<int>(n + 1, -1));
        dp.assign(n +1 , -1);
        isPal(s , 0 , n - 1);
        return recur(0 , s);
    }
};